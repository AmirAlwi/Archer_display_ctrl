#include <DMDESP.h>
#include <Arduino.h>
#include <fonts/Scoreboard.h>

#define Display_High 2
#define Display_Wide 2
#define Brightness 1
DMDESP dmd(Display_Wide, Display_High);

void setup()
{
  Serial.begin(9600); // 74880
  dmd.start();
  dmd.setBrightness(Brightness);
  dmd.setFont(Scoreboard);
  dmd.drawText(42, 1, "0");
}

static uint32_t lastmillis = 0;
int duration = -1;
int start_duration = 10;
bool run = false;

void loop()
{

  dmd.loop();
  if (duration < 0 && !run)
  {
    while (Serial.available() > 0)
    {
      char input = char(Serial.read());
      String process = String(input);
      process.trim();
      dmd.clear();
      if (process == "A")
        duration = 30;
      else if (process == "B")
        duration = 60;
      else if (process == "C")
        duration = 90;
      else if (process == "E")
        duration = 120;
      else if (process == "F")
        duration = 150;
      else if (process == "G")
        duration = 180;

      if (duration >= 100)
        dmd.drawText(0, 1, String(duration));
      else if (duration >= 10)
        dmd.drawText(21, 1, String(duration));

      start_duration = 10;
      Serial.read();
    }
  }

  if (duration > 0 && Serial.available())
  {
    char stop = char(Serial.read());
    String _stop = String(stop);
    _stop.trim();
    if (_stop == "D")
      run = !run;
    else if (_stop == "H")
    {
      run = false;
      duration = -1;
      dmd.clear();
      dmd.drawText(42, 1, "0");
    }
  }

  if (duration >= 0)
  {
    if ((millis() - lastmillis) >= 1000 && run)
    {
      dmd.clear();
      dmd.loop();
      if (start_duration < 1)
      {
        if (duration >= 100)
          dmd.drawText(0, 1, String(duration));
        else if (duration >= 10)
          dmd.drawText(21, 1, String(duration));
        else
          dmd.drawText(42, 1, String(duration));
        duration = duration - 1;
      }
      else
      {
        if (start_duration >= 10)
          dmd.drawText(21, 1, String(start_duration));
        else
          dmd.drawText(42, 1, String(start_duration));
        start_duration = start_duration - 1;
      }
      lastmillis = millis();
    }

    if (duration < 0)
    {
      run = false;
    }
  }
}
