#include <Servo.h>

void Motor(int i);
void Bump(int i);
void Curl(int i);
void Light(int i);

String recData = "";  //recording received data from upper machine
int mark = 0;
Servo myservo;

void Serial_Get(int Servo_Pin)
{	
	myservo.attach(Servo_Pin);
	static j = 0;
	int i = 0;
	while (Serial.available() > 0)
	{
		recData += char(Serial.read());
		delay(2);
		mark = 1;
	}
	if (mark == 1)
	{
		if (recData.length() > 1) // judge length
		{
			Serial.println(recData);
		}
		for (i = 0; i < recData.length(); i++)
		{
			if (recData[i] == '$')
			{
				Motor(i);
				Bump(i);
				Curl(i);
				Light(i);
			}
		}
		recData = String("");
		mark = 0;
		j = 0;
	}
}

void Motor(int i)
{
	if (recData[i + 1] == 'C'&&recData[i + 2] == 'T'&&recData[i + 3] == 'R'&&recData[i + 4] == 'L')
	{
		if (recData[i + 5] == '9'&&recData[i + 6] == '9')
		{
			digitalWrite(10, HIGH);
			digitalWrite(11, HIGH);
			digitalWrite(12, HIGH);
			digitalWrite(13, HIGH);
			Serial.println("����ر�");
		}
		else if (recData[i + 5] == '1'&&recData[i + 6] == '0')
		{
			digitalWrite(10, HIGH);
			digitalWrite(11, LOW);
			digitalWrite(12, LOW);
			digitalWrite(13, HIGH);
			Serial.println("��ת");
			delay(500);
		}
		else if (recData[i + 5] == '0'&&recData[i + 6] == '1')
		{
			digitalWrite(10, LOW);
			digitalWrite(11, HIGH);
			digitalWrite(12, HIGH);
			digitalWrite(13, LOW);
			Serial.println("��ת");
			delay(500);
		}
		else if (recData[i + 5] == '1'&&recData[i + 6] == '1')
		{
			digitalWrite(10, LOW);
			digitalWrite(11, HIGH);
			digitalWrite(12, LOW);
			digitalWrite(13, HIGH);
			Serial.println("ǰ��");
			delay(500);
		}
		else if (recData[i + 5] == '0'&&recData[i + 6] == '0')
		{
			digitalWrite(10, HIGH);
			digitalWrite(11, LOW);
			digitalWrite(12, HIGH);
			digitalWrite(13, LOW);
			Serial.println("����");
			delay(500);
		}
		else return;
	}
	digitalWrite(10, HIGH);
	digitalWrite(11, HIGH);
	digitalWrite(12, HIGH);
	digitalWrite(13, HIGH);
}

void Bump(int i)
{
	if (recData[i + 1] == 'B'&&recData[i + 2] == 'U'&&recData[i + 3] == 'M'&&recData[i + 4] == 'P')
	{
		if (recData[i + 5] == '0'&&recData[i + 6] == '0')
		{
			digitalWrite(6, HIGH);
			delay(200);
			digitalWrite(4, HIGH);
			Serial.println("ˮ��1��ˮ");
			delay(1000);
			digitalWrite(4, LOW);
			digitalWrite(6, LOW);
			digitalWrite(7, LOW);
			digitalWrite(8, LOW);
			digitalWrite(9, LOW);
			Serial.println("ˮ��1��ˮ����");
		}
		else if (recData[i + 5] == '0'&&recData[i + 6] == '1')
		{
			digitalWrite(7, HIGH);
			delay(200);
			digitalWrite(4, HIGH);
			Serial.println("ˮ��2��ˮ");
			delay(1000);
			digitalWrite(4, LOW);
			digitalWrite(6, LOW);
			digitalWrite(7, LOW);
			digitalWrite(8, LOW);
			digitalWrite(9, LOW);
			Serial.println("ˮ��2��ˮ����");
		}
		else if (recData[i + 5] == '1'&&recData[i + 6] == '0')
		{
			digitalWrite(8, HIGH);
			delay(200);
			digitalWrite(4, HIGH);
			Serial.println("ˮ��3��ˮ");
			delay(1000);
			digitalWrite(4, LOW);
			digitalWrite(6, LOW);
			digitalWrite(7, LOW);
			digitalWrite(8, LOW);
			digitalWrite(9, LOW);
			Serial.println("ˮ��3��ˮ����");
		}
		else if (recData[i + 5] == '1'&&recData[i + 6] == '1')
		{
			digitalWrite(9, HIGH);
			delay(200);
			digitalWrite(4, HIGH);
			Serial.println("ˮ��4��ˮ");
			delay(1000);
			digitalWrite(4, LOW);
			digitalWrite(6, LOW);
			digitalWrite(7, LOW);
			digitalWrite(8, LOW);
			digitalWrite(9, LOW);
			Serial.println("ˮ��4��ˮ����");
		}
		else return;
	}
}

void Curl(int i)
{
	if (recData[i + 1] == 'C'&&recData[i + 2] == 'R'&&recData[i + 3] == 'U'&&recData[i + 4] == 'L')
	{
		int tim = int(recData[6]) - 48;
		if (recData[i + 5] == '0')
		{
			myservo.write(150);              // ����Ƕ�д��
			Serial.println("��ת");
			Serial.println(tim);
			delay(tim * 1000);
			myservo.write(90);
		}
		else if (recData[i + 5] == '1')
		{
			myservo.write(30);              // ����Ƕ�д��
			Serial.println("��ת");
			Serial.println(tim);
			delay(tim * 1000);
			myservo.write(90);
		}
		else return;
	}
}

void Light(int i)
{
	if (recData[i + 1] == 'L'&&recData[i + 2] == 'I'&&recData[i + 3] == 'G'&&recData[i + 4] == 'H')
	{
		if (recData[i + 5] == '0'&&recData[i + 6] == '0')
		{
			digitalWrite(3, LOW);
			Serial.println("̽�չر�");
		}
		else  if (recData[i + 5] == '1'&&recData[i + 6] == '1')
		{
			digitalWrite(3, HIGH);
			Serial.println("̽�տ���");
		}
		else return;
	}
}
