#include <wiringPi.h>

#define out 0
#define s1 1
#define s2 2
#define s3 3
//test

int input_array[8] = [pin1,pin2,.....] 
bool board[8][8];


int main(void){
	wiringPiSetup();
	pinMode(out, OUTPUT);
	for(;;){
		digitalWrite(out, HIGH);
		delay(500);
		digitalWrite(out, LOW);
		delay(500);
	}
}
void refreshBoard(){
	/set select pins to read in all outputs
	digitalWrite(s1, LOW);
	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);
	for(int i=0; i<8; i++){
		board[i][0] = digitalRead(input_array[i]);
	}
	
	digitalWrite(s1, LOW);
	digitalWrite(s2, LOW);
	digitalWrite(s3, HIGH);
	for(int i=0; i<8; i++){
		board[i][1] = digitalRead(input_array[i]);
	}
	
	digitalWrite(s1, LOW);
	digitalWrite(s2, HIGH);
	digitalWrite(s3, LOW);
	for(int i=0; i<8; i++){
		board[i][2] = digitalRead(input_array[i]);
	}

	digitalWrite(s1, LOW);
	digitalWrite(s2, HIGH);
	digitalWrite(s3, HIGH);
	for(int i=0; i<8; i++){
		board[i][3] = digitalRead(input_array[i]);
	}
	
	digitalWrite(s1, HIGH);
	digitalWrite(s2, LOW);
	digitalWrite(s3, LOW);
	for(int i=0; i<8; i++){
		board[i][4] = digitalRead(input_array[i]);
	}
	digitalWrite(s1, HIGH);
	digitalWrite(s2, LOW);
	digitalWrite(s3, HIGH);
	for (int i = 0; i < 8; i++){
		board[i][5] = digitalRead(input_array[i]);
	}
	digitalWrite(s1, HIGH);
	digitalWrite(s2, HIGH);
	digitalWrite(s3, LOW);
	for (int i = 0; i<8; i++){
		board[i][6] = digitalRead(input_array[i]);
	}
	digitalWrite(s1, HIGH);
	digitalWrite(s2, HIGH);
	digitalWrite(s3, HIGH);
	for (int i = 0; i<8; i++){
		board[i][7] = digitalRead(input_array[i]);
	}
	
	
	
	
	//....

}
 
void detectChange(){
	bool prev_board[8][8] = board;
	Space s;
	refreshBoard();
	
	for(int i =0; i<8; i++){
		for(int j=0; j<8; j++){
			if(prev_board[i][j] != board[i][j])
				return Space(i,j);
		}
	}
	return s;
}

		

class Space{
	public:
		int i;
		int j;
		Space(){
			i = -1;
			j = -1;
		}
		Space(int ii, int jk){
			i = ii;
			j = jj;
		}
};
