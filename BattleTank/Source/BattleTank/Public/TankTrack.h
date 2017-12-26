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
    // Max force per track in newtons
    UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivaingforce = 186000; // 40 tonne tank and 1g acceleration

    virtual void BeginPlay() override;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpuls, const FHitResult& Hit);

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;

public:
    // set throttle speed / force
    UFUNCTION(BlueprintCallable, Category = Input)    
    void SetThrottle(float Throttle);	
};
