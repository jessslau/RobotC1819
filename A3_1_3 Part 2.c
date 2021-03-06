#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lightsensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           servoMotor,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title:Inputs and Outputs
Team Members: Jessica W, Jessica L, Josh, Joel
Date:1/30/19
Section:Fab Room


Task Description: to use a bump switch to start a motor


Pseudocode:
until a bump switch is pressed
start motor
until bump switch pressed
reverse motor for 3.5 seconds


*/

task main()
{

	untilBump(bumpSwitch); //until bump switch is pressed


	startMotor(rightMotor, 63); //start the motor
	startMotor(leftMotor, 63);

	untilBump(bumpSwitch); //until pressed again

	startMotor(rightMotor, -63); //reverse the motor
	startMotor(leftMotor, -63);
	wait(3.5);							//wait 3.5 seconds
	stopMotor(rightMotor); //stop the motor
	stopMotor(leftMotor);

}
