// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiftBase.generated.h"

UCLASS()
class WHATEVERYOUWANT_API ALiftBase : public AActor
{
	GENERATED_BODY()

private: 
	float StartingHeight = 0.0f;
	float EndingHeight = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default", Meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootSceneComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default", Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* LiftMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* TriggerBox = nullptr;

protected: 
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Default")
	float Height = 0.0f;



public: 
	UFUNCTION(BlueprintPure)
	float GetStartingHeight() const { return StartingHeight; }

	UFUNCTION(BlueprintPure)
	float GetEndingHeight() const { return EndingHeight; }

private: 
	UFUNCTION()
	void OnTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected: 
	UFUNCTION(BlueprintImplementableEvent, Category = "Default")
	void TriggeredEvent();

public:	
	// Sets default values for this actor's properties
	ALiftBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
