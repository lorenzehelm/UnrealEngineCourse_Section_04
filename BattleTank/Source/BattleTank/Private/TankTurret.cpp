// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "BattleTank.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Given a max rotation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);  // clamp method provides limits to value between -1 and +1
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	//auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//auto Rotation = FMath::Clamp<float>(RawNewRotation, MinRotationDegrees, MaxRotationDegrees);  //we don't need clamp on rotation instead elevation
	//SetRelativeRotation(FRotator(RawNewRotation, 0, 0));
	SetRelativeRotation(FRotator(0, Rotation, 0));
}