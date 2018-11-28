// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//UClass* ProjectileBlueprint;  // alternitive https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf 
	TSubclassOf<AProjectile> ProjectileBlueprint;  // 

	// TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // Sensible starting value of 2000 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing") 
		// EditDefaultsOnly -it works only for blueprint, and every instance has equal value
		// EditAnyWhere - it works for every indivdual instance
	float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
