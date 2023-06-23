// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CharacterAttributeSetBase.h"
#include "CharacterAbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilityPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class WHATEVERYOUWANT_API AAbilityPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAbilityPlayerState();

	// Implement IAbilitySystemInterface
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UCharacterAttributeSetBase* GetAttributeSetBase() const;

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

protected:
	UPROPERTY()
		class UCharacterAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class UCharacterAttributeSetBase* AttributeSetBase;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
