// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No tank controlled!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controlling tank: %s"), *(ControlledTank->GetName()))
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank: %s"), *(PlayerTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return PlayerPawn ? Cast<ATank>(PlayerPawn) : nullptr;
}
