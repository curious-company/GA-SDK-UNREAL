//
//  GameAnalytics.h
//  GA-SDK-IOS
//
//  Copyright (c) 2015 GameAnalytics. All rights reserved.
//

#pragma once

#include <string>
#include <vector>

namespace gameanalytics 
{
	namespace unreal
	{
		enum EGAResourceFlowType : int
	    {
	        source = 1,
	        sink = 2
	    };

	    enum EGAProgressionStatus : int
	    {
	        start = 1,
	        complete = 2,
	        fail = 3
	    };

	    enum EGAErrorSeverity : int
	    {
	        debug = 1,
	        info = 2,
	        warning = 3,
	        error = 4,
	        critical = 5
	    };

	    enum EGAGender : int
	    {
	        male = 1,
	        female = 2
	    };

		class GameAnalytics {
		public:
		    static void configureAvailableCustomDimensions01(const std::vector<std::string>& list);
		    static void configureAvailableCustomDimensions02(const std::vector<std::string>& list);
		    static void configureAvailableCustomDimensions03(const std::vector<std::string>& list);
		    
		    static void configureAvailableResourceCurrencies(const std::vector<std::string>& list);
		    static void configureAvailableResourceItemTypes(const std::vector<std::string>& list);
		    
		    static void configureBuild(const char *build);
		    static void configureUserId(const char *userId);
		    static void configureSdkGameEngineVersion(const char *gameEngineSdkVersion);
		    static void configureGameEngineVersion(const char *gameEngineVersion);
		    static void initialize(const char *gameKey, const char *gameSecret);
	    
#if PLATFORM_IOS
		    static void addBusinessEvent(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType, const char *receipt);
		    static void addBusinessEventAndAutoFetchReceipt(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType);
#elif PLATFORM_ANDROID
	    	static void addBusinessEvent(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType, const char *receipt, const char *signature);
#endif
		    static void addBusinessEvent(const char *currency, int amount, const char *itemType, const char *itemId, const char *cartType);
		    static void addResourceEvent(EGAResourceFlowType flowType, const char *currency, float amount, const char *itemType, const char *itemId);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01, int score);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01, const char *progression02);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01, const char *progression02, int score);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01, const char *progression02, const char *progression03);
		    static void addProgressionEvent(EGAProgressionStatus progressionStatus, const char *progression01, const char *progression02, const char *progression03, int score);
		    static void addDesignEvent(const char *eventId);
		    static void addDesignEvent(const char *eventId, float value);
		    static void addErrorEvent(EGAErrorSeverity severity, const char *message);
		    
		    static void setEnabledInfoLog(bool flag);
		    static void setEnabledVerboseLog(bool flag);
		    static void setCustomDimension01(const char *customDimension);
		    static void setCustomDimension02(const char *customDimension);
		    static void setCustomDimension03(const char *customDimension);
		    static void setFacebookId(const char *facebookId);
		    static void setGender(EGAGender gender);
		    static void setBirthYear(int birthYear);
		};
	}
}