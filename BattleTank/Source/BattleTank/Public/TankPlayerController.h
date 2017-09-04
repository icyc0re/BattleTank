// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Override BeginPlay inherited from AActor
	virtual void BeginPlay() override;

	// Get pointer to controlled Tank (casted to ATank)
	ATank* GetControlledTank() const;
};
