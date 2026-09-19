/*用枚举模拟一个小状态机：enum State {IDLE, RUNNING, STOPPED}；
写一个函数根据当前状态 + 输入事件打印"状态转移"
（比如 IDLE+start→RUNNING）。体会枚举在嵌入式状态管理里的用法*/
/*
enum State { IDLE, RUNNING, STOPPED };（默认 0/1/2）
定义"事件"：enum Event { START, STOP, RESET };
写函数 enum State on_event(enum State cur, enum Event e)，根据当前状态 + 事件返回新状态：
IDLE + START → RUNNING
RUNNING + STOP → STOPPED
STOPPED + RESET → IDLE
其他组合 → 状态不变（保持原样）
main 里用枚举常量名（不要写 0/1/2 数字）演示一段转移：IDLE 收到 START、再收到 STOP、
再收到 RESET，每步打印"当前状态→事件→新状态"和最终状态。
验收：转移链路正确，且全程只用枚举名、switch 覆盖所有事件分支（default 处理"状态不变"）。

提示：函数返回类型是 enum State，参数也是 enum State/enum Event——这是 C 里"状态机"的标准写法，
M4 写摄像头/V4L2 设备状态时会用到同类思路。*/
#include <stdio.h>
enum State{
    IDLE,RUNNING,STOPPED
};

enum Event{
    START,STOP,RESET
};
enum State on_Event(enum State s,enum Event e){
    switch (s){
        case IDLE: 
        if(e==START) {return RUNNING;} break;
        case RUNNING:
        if(e==STOP) {return STOPPED;} break;
        case STOPPED:
        if(e==RESET){return IDLE;} break;
        default : break;  
}
return s;}

const char*state_name(enum State s1){ //打印state中文
    switch(s1){
        case IDLE:return "IDLE";
        case RUNNING: return "RUNNING";
        case STOPPED: return "STOPPED";
        default :return "状态不变";
    }
}

const char*event_name(enum Event e1){ //打印event中文
    switch (e1){
        case START: return "START";
        case STOP : return "STOP";
        case RESET: return "RESET";
        default : return "状态不变";
    }
}

int main(){
    enum State a=IDLE;
    enum Event b=START;
    enum State new=on_Event(a,b);
    printf("%s->%s->%s\n",state_name(a),event_name(b),state_name(new));
    a=new;

    b=STOP;
    new=on_Event(a,b);
    printf("%s->%s->%s\n",state_name(a),event_name(b),state_name(new));
    a=new;

    b=RESET;
    new=on_Event(a,b);
    printf("%s->%s->%s\n",state_name(a),event_name(b),state_name(new));
    a=new;

    printf("最终状态为%s\n",state_name(a));
    return 0;

}