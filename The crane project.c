#pragma config(Sensor, in1,    linefollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lightsensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitswitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpswitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlight,    tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           turnMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lowerMotor,    tmotorVex269_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title:Inputs and Outputs
Team Members: Jessica W, Jessica L, Josh, Joel
Date:2/27/19
Section:Fab Room


Task Description: To create a crane that can pick up an object and bring it to a designated location


Pseudocode:
The motor spins the crane (MOTOR A)
if(the ultrasonic sensor value changes)
MOTOR A stops
motor that lowers the string spins(MOTOR B)
motor B reverses direction

while the line follower is black
the motor that control movement spin (MOTORS C and MOTORS D)


*/

// things that need to be found out
//- distance of magnets at beginning
//- time taken for the string to reach the magnet
//- line follower black value
// - set up lowerMotor


task main()
{                                     //Program begins, insert code within curly braces

	startMotor(turnMotor,11);    			//makes the crane of the robot spin
	untilSonarLessThan(7, sonar);   		//when an object is detected under the crane
	stopMotor(turnMotor);				//stops the crane from spinning
	startMotor(lowerMotor,100);			//starts the motor that lowers the string
	wait(2.5);					//motor lowers string for 2.5 seconds
	stopMotor(lowerMotor);				//motor stops lowering string
	startMotor(lowerMotor,-100);			//motor raises string 
	wait(2.5);					//motor raises string for 2.5 seconds
	stopMotor(lowerMotor);				//motor stops raising string
	startMotor(rightMotor,100);			//the right wheel motor begins to turn
	startMotor(leftMotor,-100);			//the left wheel motor begins to turn 									
	waitUntil(SensorValue(linefollower)<=2800);	//when line follower stops detecting black line
	stopMotor(rightMotor);				//right motor stops
	stopMotor(leftMotor);				//left motor stops

}
