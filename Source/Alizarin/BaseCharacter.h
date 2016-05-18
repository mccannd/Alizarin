// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Engine.h"
#include "Weapon.h"
#include "BaseCharacter.generated.h"




UCLASS(Blueprintable)
class ALIZARIN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// health float
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
		float Health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
		FResistanceStruct resistances;

	// dead state
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BaseCharacter")
		bool isDead = false;

	// expose health calculation
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		virtual void CalculateHealth(float delta);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		virtual void CalculateDamage(FDamageStruct damage);

	// for editor interaction
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
