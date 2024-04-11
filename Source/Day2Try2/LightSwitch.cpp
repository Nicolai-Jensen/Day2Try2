// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	LightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));


	RootComponent = CollisionComponent;
	ButtonMesh->SetupAttachment(RootComponent);
	LightComponent->SetupAttachment(RootComponent);

	lightState = ELightState::OFF;
	bIsLightOn = false;
}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
	if (LightComponent)
	{
		LightComponent->SetVisibility(bIsLightOn);
	}
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::Use_Implementation()
{

	if (lightState == ELightState::OFF)
	{
		bIsLightOn = true;
		lightState = ELightState::ON;
	}
	else if (lightState == ELightState::ON)
	{
		bIsLightOn = false;
		lightState = ELightState::OFF;
	}

	if (LightComponent)
	{
		LightComponent->SetVisibility(bIsLightOn);
	}
}

