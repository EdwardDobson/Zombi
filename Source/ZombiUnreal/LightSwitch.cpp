// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "LightSwitch.h"
#include "Macros.h"
// Sets default values
ALightSwitch::ALightSwitch()
{
	DesiredIntensity = 3000.0f;
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->Intensity = DesiredIntensity;
	PointLight->SetVisibility(false);
	RootComponent = PointLight;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(250.0f);
	Sphere->SetupAttachment(RootComponent);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitch::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitch::OnOverlapEnd);
}

void ALightSwitch::OnOverlapBegin(class UPrimitiveComponent *_overlappedComp, class AActor *_otherActor, class UPrimitiveComponent *_otherComp, int32 _otherBodyIndex, bool _bFromSweep, const FHitResult &_sweepResult)
{
	if (_otherActor && (_otherActor != this) && _otherComp)
	{
		ToggleLight();
	}
}

void ALightSwitch::OnOverlapEnd(class UPrimitiveComponent *_overlappedComp, class AActor *_otherActor, class UPrimitiveComponent *_otherComp, int32 _otherBodyIndex)
{
	if (_otherActor && (_otherActor != this) && _otherComp)
	{
		ToggleLight();
	}
}

void ALightSwitch::ToggleLight()
{
	DebugOutInt(PointLight->Intensity);
	PointLight->ToggleVisibility();
}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
