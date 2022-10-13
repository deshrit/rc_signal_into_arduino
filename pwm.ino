// Input from receiver to pin 11
const int ch_2_pin = 11;
// Read value
unsigned long ch_2_val;

int deadzone = 20;


// -------------------------- setup ------------------------------ 
void setup()
{
  Serial.begin(9600);
}

// -------------------------- main loop -------------------------- 
void loop()
{
  // Reading input
  ch_2_val = pulseIn(ch_2_pin, HIGH, 2500);
  // Print to serial moniter
  Serial.println(pwm(ch_2_val));
}


// Converting function
int pwm(int pulse) {
  if(pulse >= 1000 && pulse <= 2000){
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);
  }
  else {
    pulse = 0;
  }
  if(abs(pulse) <= 20) {
    pulse = 0;
  }
  return pulse;
}
