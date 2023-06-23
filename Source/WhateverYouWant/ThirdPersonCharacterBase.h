// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "CharacterAttributeSetBase.h"
#include "CharacterAbilitySystemComponent.h"
#include "AbilityPlayerState.h"
#include "AbilitySystemReplicationProxyInterface.h"
#include "ThirdPersonCharacterBase.generated.h"

UCLASS()
class WHATEVERYOUWANT_API AThirdPersonCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UCharacterAttributeSetBase* AttributeSetBase;

public:
	// Sets default values for this character's properties
	AThirdPersonCharacterBase(const class FObjectInitializer& objectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Inherited via IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
