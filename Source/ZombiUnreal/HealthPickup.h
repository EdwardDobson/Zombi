// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "HealthPickup.generated.h"

UCLASS()
class ZOMBIUNREAL_API AHealthPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPickup();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;
		UFUNCTION()
	void OnOverlap(AActor* _this, AActor* _other);
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DamagePlayer;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
