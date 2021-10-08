// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitch.generated.h"

UCLASS()
class ZOMBIUNREAL_API ALightSwitch : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightSwitch();
	UPROPERTY(VisibleAnywhere, Category = "Switch")
	class UPointLightComponent *PointLight;

	UPROPERTY(VisibleAnywhere, Category = "Switch")
	class USphereComponent *Sphere;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent *_overlappedComp, class AActor *_otherActor, class UPrimitiveComponent *_otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult &_sweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent *_overlappedComp, class AActor *_otherActor, class UPrimitiveComponent *_otherComp, int32 _otherBodyIndex);
	UFUNCTION()
	void ToggleLight();

	UPROPERTY(VisibleAnywhere, Category = "Switch")
	float DesiredIntensity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
