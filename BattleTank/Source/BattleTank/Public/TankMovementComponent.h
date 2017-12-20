// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"



class UTankTrack;



/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
		
private:
    UTankTrack *LeftTrack = nullptr;
    UTankTrack *RightTrack = nullptr;

    // Called from the pathfinding logic by the ai controllers
    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

public:
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendMoveForward(float Throw);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void IntendTurnRight(float Throw);    
};
