// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Macros.h"
#include "GunWeapon.generated.h"

UCLASS()
class ZOMBIUNREAL_API AGunWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGunWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxReloadTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxFireRateTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	float FireRate;
	float ReloadTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString GunName;
};
