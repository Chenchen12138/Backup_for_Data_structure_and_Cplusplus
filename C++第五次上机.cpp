#include <iostream>
using namespace std;

class Command
{
public:
	virtual void on()=0;
	virtual void off()=0;
};
class Light
{
public:
	void turnLight(int degree);	
};
class TV
{
public:
	void serChannel(int channel);	
};
class RemoteControl
{
protected:
	Command *commands[4];
public:
	void PressButton(int button)
	{
		if(button%2==0)
			commands[button]->on();
		else
			commands[button]->off();
	}
	void setCommand(int button, Command *command)
	{
		commands[button]=command;
	}
};
class LightCommand:public Command
{
protected:
	Light *light;
public:
	LightCommand(Light *light){this->light=light;}
	virtual void on()
	{
		light->turnLight(100);
	}
	virtual void off()
	{
		light->turnLight(0);
	}
};
class TVCommand:public Command
{
protected:
	Tv *tv;
public:
	TVCommand(TV *tv){this->tv=tv;}
	virtual void on()
	{
		tv->serChannel(1);
	}
	virtual void off()
	{
		tv->serChannel(0);
	}	
}:

int main()
{
	return 0;
}