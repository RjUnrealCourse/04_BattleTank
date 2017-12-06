// Ramachandra Junior.  Copyright 2016. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Use to set maximum driving force, and to move tank
 */
UCLASS(ClassGroup = (Setup), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
    UPROPERTY(EditDefaultsOnly)
    float TankMaxDrivaingforce = 10000 * 23; // Max force per track in newtons

public:
    // set throttle speed / force
    UFUNCTION(BlueprintCallable, Category = Input)    
    void SetThrottle(float Throttle);	
};
