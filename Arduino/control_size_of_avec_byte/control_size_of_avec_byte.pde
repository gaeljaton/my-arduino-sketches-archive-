
byte data8[ ] = {114	,	156	,
230	,	206	,
206	,	231	,
156	,	115	,
56	,	57	,
114	,	156	,
230	,	206	,
204	,	231	,
156	,	115	,
56	,	57	,
};    // first analog sensor
    // incoming serial byte

void setup()
{
  
  Serial.begin(9600);
} 
void loop()
{

    Serial.print(sizeof(data8));
    delay (500);
 
}


