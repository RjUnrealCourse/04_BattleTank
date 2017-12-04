// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Holds barrel's properties
 */
UCLASS(ClassGroup = (Setup), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
    // -1 is max downward speed, and +1 is max up speed
    void Elevate(float RelativeSpeed);

private:
    UPROPERTY(EditAnywhere)
    float MaxDegreesPerSecond;
	
    UPROPERTY(EditAnywhere)
    float MaxElevationDegrees = 40.f;

    UPROPERTY(EditAnywhere)
    float MinElevationDegrees = 0.f;

};

