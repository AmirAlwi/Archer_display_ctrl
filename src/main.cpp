#include <DMDESP.h>
#include <Arduino.h>
#include <fonts/Scoreboard.h>

#define Display_High 2
#define Display_Wide 2
#define Brightness 1
DMDESP dmd(Display_Wide, Display_High);

enum status{
	start = 0,
	stop,
	reset,
	idle,
	busy,
};

void setup()
{
	Serial.begin(9600); // 74880
	dmd.start();
	dmd.setBrightness(Brightness);
	dmd.setFont(Scoreboard);
	dmd.drawText(42, 1, "0");
}

static uint32_t lastmillis = 0;
int duration = -1, countdown = -1;
int start_duration = 10;

int timer = reset;
int status = idle;


void loop()
{
	dmd.loop();
	if (status == idle){
		while(status==idle){
			dmd.refresh();
			if (Serial.available()){
				char input = char(Serial.read());
				String _input = String(input);
				_input.trim();
				if(_input == "A" || _input == "B" || \
					_input == "C" || _input == "E" || \
					_input == "F" || _input == "G"){ //timer
						dmd.clear();
						if (_input == "A")
							duration = 30;
						else if (_input == "B")
							duration = 60;
						else if (_input == "C")
							duration = 90;
						else if (_input == "E")
							duration = 120;
						else if (_input == "F")
							duration = 150;
						else if (_input == "G")
							duration = 180;

						countdown = duration;   
						if (countdown >= 100)
							dmd.drawText(0, 1, String(countdown));
						else if (countdown >= 10)
							dmd.drawText(21, 1, String(countdown));
				}

				if(_input == "D" || _input == "H"){

					if (_input == "D"){//start
						timer = start;
						status = busy;
					}
					else if(_input == "H"){ //reset
						dmd.clear();
						duration = 0;
						countdown = 0;
        				dmd.drawText(42, 1, "0");
						start_duration = 10;
					}
				}
				_input = 0;
			}
		}
	}
	else if (status == busy){
		lastmillis = millis();
		while(status == busy)
		{
			dmd.refresh();
			if (Serial.available()){
				char input = char(Serial.read());
				String _input = String(input);
				_input.trim();

				if(_input == "D" || _input == "H"){

					if (_input == "D"){//start/stop
						if(timer == start)
							timer = stop;
						else if(timer == stop)
							timer = start;
					}
					else if(_input == "H" && timer == stop){ //reset
						dmd.clear();
						status = idle;
						countdown = duration;
						start_duration = 10;
						if (countdown >= 100)
							dmd.drawText(0, 1, String(countdown));
						else if (countdown >= 10)
							dmd.drawText(21, 1, String(countdown));
						break;
					}

				}
			}

			if ((timer == start )&& (millis()-lastmillis >= 1000)){
				dmd.clear();

   				lastmillis = millis();

				if (start_duration < 1){

					if (countdown >= 100)
						dmd.drawText(0, 1, String(countdown));
					else if (countdown >= 10)
						dmd.drawText(21, 1, String(countdown));
					else
						dmd.drawText(42, 1, String(countdown));
					countdown = countdown - 1;

				} else {
					
					if (start_duration >= 10)
						dmd.drawText(21, 1, String(start_duration));
					else
						dmd.drawText(42, 1, String(start_duration));
					
					if (start_duration == 10)
						Serial.write("2");
					start_duration = start_duration - 1;
					if (start_duration <1)
						Serial.write("1");
				}

				if (countdown < 0)
				{	
					Serial.write("3");
					timer = stop;
					status = idle;
					countdown = duration;
					if (countdown >= 100)
						dmd.drawText(0, 1, String(countdown));
					else if (countdown >= 10)
						dmd.drawText(21, 1, String(countdown));
					start_duration = 10;
					break;
				}

			}
		}
	}
}
