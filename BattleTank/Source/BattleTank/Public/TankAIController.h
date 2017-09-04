// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Override of BeginPlay inherited from AActor
	virtual void BeginPlay() override;

	// Get pointer to controlled Tank (casted to ATank)
	ATank* GetControlledTank() const;
};
