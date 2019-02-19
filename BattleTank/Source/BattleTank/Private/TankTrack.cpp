// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

#include "Components/PrimitiveComponent.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *(GetForwardVector() * FVector(1.0f, 1.0f, 0.0f)).ToString())
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
