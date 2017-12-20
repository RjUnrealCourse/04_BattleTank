// Ramachandra Junior.  Copyright 2016. All rights reserved.

#include "TankMovementComponent.h"
#include "TankTrack.h"




void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
    return;
}



void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    // Set the same throttle on both of them     
    LeftTrack->SetThrottle(Throw); // we need to set same force on both of them to move forward
    RightTrack->SetThrottle(Throw);

    // TODO prevent double-speed due to dual control use
    return;
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!LeftTrack || !RightTrack) { return; }
    // Set the same throttle on both of them     
    LeftTrack->SetThrottle(Throw); // we need to set same force on both of them to move forward
    RightTrack->SetThrottle(-1 * Throw);

    // TODO prevent double-speed due to dual control use
    return;
}



void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
    // No need to call Super as we're replacing the functionality
    
    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal(); // Direction of tank
    auto AIForwardIntention = MoveVelocity.GetSafeNormal(); // direction AI wants us to move
        
    auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward); // dunno?
    // send move forward signal
    //IntendMoveForward(ResultantMag);

    auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
    IntendTurnRight(RightThrow.Z);        
}
