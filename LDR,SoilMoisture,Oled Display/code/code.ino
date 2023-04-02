#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    4  // Reset pin # (or -1 if sharing reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int moist,light; 
void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 allocation failed");
    while(1); //Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);  
  display.setTextSize(4);
  display.setCursor(10, 20);
  display.print("OLED");
  display.display();
  delay(2000);  
  display.setTextSize(3);  
}
 
void loop()
{
  int moist_value,light_value;
  moist_value = analogRead(A1);
  light_value = analogRead(A2);
  moist = map(moist_value,1020,25,0,100);
  light = map(light_value,15,1015,0,100);  
  display.clearDisplay();
  delay(200);
  display.setCursor(5, 0);
  display.println("Mo:");
  display.setCursor(5, 35);
  display.println("Li:");
  display.display();
  display.setCursor(60,0);
  display.print(moist);
  display.setCursor(110,0);
  display.print('%');
  display.setCursor(60,35);
  display.print(light);
  display.setCursor(110,35);
  display.print('%');
  display.display();
  delay(1000);
 }
