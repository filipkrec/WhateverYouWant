// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include <WhateverYouWant/ThirdPersonCharacterBase.h>

// Sets default values
ALiftBase::ALiftBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);

	LiftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LiftMesh"));
	LiftMesh -> SetupAttachment(RootSceneComponent);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox -> SetupAttachment(LiftMesh);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALiftBase::OnTriggered);
}

// Called when the game starts or when spawned
void ALiftBase::BeginPlay()
{
	Super::BeginPlay();

	StartingHeight = GetActorLocation().Z;
	EndingHeight = StartingHeight + Height;
}

// Called every frame
void ALiftBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ALiftBase::OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AThirdPersonCharacterBase* thirdPersonCharacter = Cast<AThirdPersonCharacterBase>(OtherActor);

	if (thirdPersonCharacter != nullptr)
	{
		TriggeredEvent();
	}
}
