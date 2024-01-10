#define lms 5
#define lmf 6
#define lmb 7
#define rmf 8
#define rmb 9
#define rms 10

int s[6], sum, avg;
int base[6] = { 1, 2, 4, 8, 16, 32 };
int position[6] = { 1, 2, 3, 4, 5, 6 };
int threshold = 512;
int sensor;

int 1sp = 25, rsp = 25, tsp = 250;
int lbase = 200, rbase = 200;
int lmotor, rmotor;
float line_prop = 3;
double kp = 50, kd = 1000, ki = 0.01;
int PID;
int error[10];
int pos;
char turn = 's';

void setup() {
pinMode(1mf, OUTPUT);
pinMode(1mb, OUTPUT);
pinMode(rmf, OUTPUT);
pinMode(rmb, OUTPUT);
// motor(10 * 1sp, 10 * rsp);

}

void loop() {

// line_follow();
// semi_pid();
}
