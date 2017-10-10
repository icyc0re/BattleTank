// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward declarations
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Override BeginPlay inherited from AActor
	virtual void BeginPlay() override;

	// Override Tick inherited from AActor
	virtual void Tick(float) override;

private:
	// Get pointer to controlled Tank (casted to ATank)
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	// Cast linetrace in the crosshair direction and see if we hit any visible element
	bool GetSightRayHitLocation(FVector&) const;

	// Compute look direction and save it in the second parameter
	bool GetLookDirection(FVector2D, FVector&) const;

	// Linetrace in a specific direction and save the hit location in the second parameter
	bool GetLookVectorHitLocation(const FVector&, FVector&) const;

	// Relative location of crosshair on the screen (X axis)
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	// Relative location of crosshair on the screen (Y axis)
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.333;

	// Max distance of the aiming linetrace
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0; // 1 -> 1cm
};
