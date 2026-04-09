const int R1 = 10000;
const int Vin = 3300;
const int WINDOW_SIZE = 10;
double readSet[WINDOW_SIZE] = {0};
int count = 0;
double voltage = 0;
double res = 0;
double res_sum;
double res_avg = 0;


//---------------

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < WINDOW_SIZE;i++){
    voltage = analogReadMilliVolts(4);

    if(Vin - voltage != 0){
      res = (voltage*R1)/(Vin-voltage);
    }
    readSet[i] = res;

  }
}
void loop() {
  voltage = analogReadMilliVolts(4);

  if(Vin - voltage != 0){
    res = (voltage*R1)/(Vin-voltage);
  }

  readSet[count] = res;
  count++;
  if(count == WINDOW_SIZE){
    count = 0;
  }
  res_sum = 0;
  for(int x = 0; x < WINDOW_SIZE; x++){
      res_sum += readSet[x]; 
    }
  res_avg = res_sum/10;

  Serial.print("Rezystancja wynosi: ");
  Serial.print(res_avg);
  Serial.println("Ω");
  delay(1000);
}
