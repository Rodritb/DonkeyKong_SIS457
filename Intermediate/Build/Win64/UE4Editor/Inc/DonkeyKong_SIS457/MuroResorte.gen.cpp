// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_SIS457/MuroResorte.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMuroResorte() {}
// Cross Module References
	DONKEYKONG_SIS457_API UClass* Z_Construct_UClass_AMuroResorte_NoRegister();
	DONKEYKONG_SIS457_API UClass* Z_Construct_UClass_AMuroResorte();
	DONKEYKONG_SIS457_API UClass* Z_Construct_UClass_AObstaculo();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_SIS457();
// End Cross Module References
	void AMuroResorte::StaticRegisterNativesAMuroResorte()
	{
	}
	UClass* Z_Construct_UClass_AMuroResorte_NoRegister()
	{
		return AMuroResorte::StaticClass();
	}
	struct Z_Construct_UClass_AMuroResorte_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMuroResorte_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AObstaculo,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_SIS457,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMuroResorte_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MuroResorte.h" },
		{ "ModuleRelativePath", "MuroResorte.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMuroResorte_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMuroResorte>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMuroResorte_Statics::ClassParams = {
		&AMuroResorte::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMuroResorte_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMuroResorte_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMuroResorte()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMuroResorte_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMuroResorte, 722387182);
	template<> DONKEYKONG_SIS457_API UClass* StaticClass<AMuroResorte>()
	{
		return AMuroResorte::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMuroResorte(Z_Construct_UClass_AMuroResorte, &AMuroResorte::StaticClass, TEXT("/Script/DonkeyKong_SIS457"), TEXT("AMuroResorte"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMuroResorte);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
