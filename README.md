# rccar-using-arduino
*Remote controlled car equipped with bluetooth and radio transmissions*


Remote control car using Arduino and NRF radio module/HC05 Bluetooth module
The files can individually be donwloaded and compiled using Arduino IDE and uploaded into your Arduino board(anything above Nano). 

CONNECTIONS

![image](https://user-images.githubusercontent.com/59359627/184305166-e2cc94b3-77d5-4e46-b3e2-679d56461afe.png)

### HC 05 Blutooth Module
Use the following link to download remote : [Mobile App](https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en_IN&gl=US)
1. Variable speeds can be set by using the slider on top right.
2. An audio track is played if the triangle button is played
      This is done using a piezo buzzer and frequency functions.



### NRF24L01 module
2 NRF modules need to be used, one as receiver and the other as transmitter. 
The Transmitter code has to be configured according to the key binding in the source code
