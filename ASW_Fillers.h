/*******************************************************************************/
/* Copyright XXXXXXXXX 1998-YYYY                                               */
/*                                                                             */
/* xxxxxxxx@xxxxx.xxx                                                          */
/*******************************************************************************/

#ifndef ASWF_Fillers_H
#define ASWF_Fillers_H

/* system includes-------------------------------------------------------------*/
/* none */
/* application includes-------------------------------------------------------------*/
#include <myTypes.h>
/* component includes-------------------------------------------------------------*/
#include <ASW_FillersUser.h>

/* macros-------------------------------------------------------------*/
//packet IDs
#define ASW_SUCCESSREPORT_PACKETID (0x0101)
#define ASW_SUCCESSREPORT_SERVICE ((ASW_SUCCESSREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_SUCCESSREPORT_SUBSERVICE (ASW_SUCCESSREPORT_PACKETID & (0x00FF))
#define ASW_FAILREPORT_PACKETID (0x0102)
#define ASW_FAILREPORT_SERVICE ((ASW_FAILREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_FAILREPORT_SUBSERVICE (ASW_FAILREPORT_PACKETID & (0x00FF))
#define ASW_SUCCESSEXECUTIONREPORT_PACKETID (0x0107)
#define ASW_SUCCESSEXECUTIONREPORT_SERVICE ((ASW_SUCCESSEXECUTIONREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_SUCCESSEXECUTIONREPORT_SUBSERVICE (ASW_SUCCESSEXECUTIONREPORT_PACKETID & (0x00FF))
#define ASW_FAILEXECUTIONREPORT_PACKETID (0x0108)
#define ASW_FAILEXECUTIONREPORT_SERVICE ((ASW_FAILEXECUTIONREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_FAILEXECUTIONREPORT_SUBSERVICE (ASW_FAILEXECUTIONREPORT_PACKETID & (0x00FF))
#define ASW_HKREPORTENABLE_PACKETID (0x0305)
#define ASW_HKREPORTENABLE_SERVICE ((ASW_HKREPORTENABLE_PACKETID & (0xFF00)) >> 8)
#define ASW_HKREPORTENABLE_SUBSERVICE (ASW_HKREPORTENABLE_PACKETID & (0x00FF))
#define ASW_HKREPORTDISABLE_PACKETID (0x0306)
#define ASW_HKREPORTDISABLE_SERVICE ((ASW_HKREPORTDISABLE_PACKETID & (0xFF00)) >> 8)
#define ASW_HKREPORTDISABLE_SUBSERVICE (ASW_HKREPORTDISABLE_PACKETID & (0x00FF))
#define ASW_HKREPORT_PACKETID (0x0319)
#define ASW_HKREPORT_SERVICE ((ASW_HKREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_HKREPORT_SUBSERVICE (ASW_HKREPORT_PACKETID & (0x00FF))
#define ASW_HKGENERATE_PACKETID (0x031B)
#define ASW_HKGENERATE_SERVICE ((ASW_HKGENERATE_PACKETID & (0xFF00)) >> 8)
#define ASW_HKGENERATE_SUBSERVICE (ASW_HKGENERATE_PACKETID & (0x00FF))
#define ASW_HKCHANGEPERIOD_PACKETID (0x031F)
#define ASW_HKCHANGEPERIOD_SERVICE ((ASW_HKCHANGEPERIOD_PACKETID & (0xFF00)) >> 8)
#define ASW_HKCHANGEPERIOD_SUBSERVICE (ASW_HKCHANGEPERIOD_PACKETID & (0x00FF))
#define ASW_EVENTINFORMATIVE_PACKETID (0x0501)
#define ASW_EVENTINFORMATIVE_SERVICE ((ASW_EVENTINFORMATIVE_PACKETID & (0xFF00)) >> 8)
#define ASW_EVENTINFORMATIVE_SUBSERVICE (ASW_EVENTINFORMATIVE_PACKETID & (0x00FF))
#define ASW_EVENTLOWSEVERITY_PACKETID (0x0502)
#define ASW_EVENTLOWSEVERITY_SERVICE ((ASW_EVENTLOWSEVERITY_PACKETID & (0xFF00)) >> 8)
#define ASW_EVENTLOWSEVERITY_SUBSERVICE (ASW_EVENTLOWSEVERITY_PACKETID & (0x00FF))
#define ASW_EVENTMEDIUMSEVERITY_PACKETID (0x0503)
#define ASW_EVENTMEDIUMSEVERITY_SERVICE ((ASW_EVENTMEDIUMSEVERITY_PACKETID & (0xFF00)) >> 8)
#define ASW_EVENTMEDIUMSEVERITY_SUBSERVICE (ASW_EVENTMEDIUMSEVERITY_PACKETID & (0x00FF))
#define ASW_EVENTHIGHSEVERITY_PACKETID (0x0504)
#define ASW_EVENTHIGHSEVERITY_SERVICE ((ASW_EVENTHIGHSEVERITY_PACKETID & (0xFF00)) >> 8)
#define ASW_EVENTHIGHSEVERITY_SUBSERVICE (ASW_EVENTHIGHSEVERITY_PACKETID & (0x00FF))
#define ASW_EXECUTEFUNCTION_PACKETID (0x0801)
#define ASW_EXECUTEFUNCTION_SERVICE ((ASW_EXECUTEFUNCTION_PACKETID & (0xFF00)) >> 8)
#define ASW_EXECUTEFUNCTION_SUBSERVICE (ASW_EXECUTEFUNCTION_PACKETID & (0x00FF))
#define ASW_STOPFUNCTION_PACKETID (0x0880)
#define ASW_STOPFUNCTION_SERVICE ((ASW_STOPFUNCTION_PACKETID & (0xFF00)) >> 8)
#define ASW_STOPFUNCTION_SUBSERVICE (ASW_STOPFUNCTION_PACKETID & (0x00FF))
#define ASW_UPDATETIME_PACKETID (0x0984)
#define ASW_UPDATETIME_SERVICE ((ASW_UPDATETIME_PACKETID & (0xFF00)) >> 8)
#define ASW_UPDATETIME_SUBSERVICE (ASW_UPDATETIME_PACKETID & (0x00FF))
#define ASW_CONNECTIONTEST_PACKETID (0x1103)
#define ASW_CONNECTIONTEST_SERVICE ((ASW_CONNECTIONTEST_PACKETID & (0xFF00)) >> 8)
#define ASW_CONNECTIONTEST_SUBSERVICE (ASW_CONNECTIONTEST_PACKETID & (0x00FF))
#define ASW_CONNECTIONREPORT_PACKETID (0x1104)
#define ASW_CONNECTIONREPORT_SERVICE ((ASW_CONNECTIONREPORT_PACKETID & (0xFF00)) >> 8)
#define ASW_CONNECTIONREPORT_SUBSERVICE (ASW_CONNECTIONREPORT_PACKETID & (0x00FF))
#define ASW_SETMODE_PACKETID (0x8001)
#define ASW_SETMODE_SERVICE ((ASW_SETMODE_PACKETID & (0xFF00)) >> 8)
#define ASW_SETMODE_SUBSERVICE (ASW_SETMODE_PACKETID & (0x00FF))
#define ASW_SETPICTUREPARAMETERS_PACKETID (0x8002)
#define ASW_SETPICTUREPARAMETERS_SERVICE ((ASW_SETPICTUREPARAMETERS_PACKETID & (0xFF00)) >> 8)
#define ASW_SETPICTUREPARAMETERS_SUBSERVICE (ASW_SETPICTUREPARAMETERS_PACKETID & (0x00FF))
#define ASW_SETCAMERAPARAMETERS_PACKETID (0x8003)
#define ASW_SETCAMERAPARAMETERS_SERVICE ((ASW_SETCAMERAPARAMETERS_PACKETID & (0xFF00)) >> 8)
#define ASW_SETCAMERAPARAMETERS_SUBSERVICE (ASW_SETCAMERAPARAMETERS_PACKETID & (0x00FF))
#define ASW_SETSEQUENCEPARAMETERS_PACKETID (0x8004)
#define ASW_SETSEQUENCEPARAMETERS_SERVICE ((ASW_SETSEQUENCEPARAMETERS_PACKETID & (0xFF00)) >> 8)
#define ASW_SETSEQUENCEPARAMETERS_SUBSERVICE (ASW_SETSEQUENCEPARAMETERS_PACKETID & (0x00FF))
#define ASW_SAVEPARAMETERS_PACKETID (0x8005)
#define ASW_SAVEPARAMETERS_SERVICE ((ASW_SAVEPARAMETERS_PACKETID & (0xFF00)) >> 8)
#define ASW_SAVEPARAMETERS_SUBSERVICE (ASW_SAVEPARAMETERS_PACKETID & (0x00FF))
#define ASW_CLEARPARAMETERS_PACKETID (0x8006)
#define ASW_CLEARPARAMETERS_SERVICE ((ASW_CLEARPARAMETERS_PACKETID & (0xFF00)) >> 8)
#define ASW_CLEARPARAMETERS_SUBSERVICE (ASW_CLEARPARAMETERS_PACKETID & (0x00FF))
#define ASW_IMAGEMETADATA_PACKETID (0x8007)
#define ASW_IMAGEMETADATA_SERVICE ((ASW_IMAGEMETADATA_PACKETID & (0xFF00)) >> 8)
#define ASW_IMAGEMETADATA_SUBSERVICE (ASW_IMAGEMETADATA_PACKETID & (0x00FF))
#define ASW_IMAGESEGMENT_PACKETID (0x8008)
#define ASW_IMAGESEGMENT_SERVICE ((ASW_IMAGESEGMENT_PACKETID & (0xFF00)) >> 8)
#define ASW_IMAGESEGMENT_SUBSERVICE (ASW_IMAGESEGMENT_PACKETID & (0x00FF))
#define ASW_GETSEQUENCEPARAMETERSVALUE_PACKETID (0x8009)
#define ASW_GETSEQUENCEPARAMETERSVALUE_SERVICE ((ASW_GETSEQUENCEPARAMETERSVALUE_PACKETID & (0xFF00)) >> 8)
#define ASW_GETSEQUENCEPARAMETERSVALUE_SUBSERVICE (ASW_GETSEQUENCEPARAMETERSVALUE_PACKETID & (0x00FF))
#define ASW_SEQUENCEPARAMETERSVALUE_PACKETID (0x800A)
#define ASW_SEQUENCEPARAMETERSVALUE_SERVICE ((ASW_SEQUENCEPARAMETERSVALUE_PACKETID & (0xFF00)) >> 8)
#define ASW_SEQUENCEPARAMETERSVALUE_SUBSERVICE (ASW_SEQUENCEPARAMETERSVALUE_PACKETID & (0x00FF))
#define ASW_CLEARIMAGESTORAGE_PACKETID (0x800B)
#define ASW_CLEARIMAGESTORAGE_SERVICE ((ASW_CLEARIMAGESTORAGE_PACKETID & (0xFF00)) >> 8)
#define ASW_CLEARIMAGESTORAGE_SUBSERVICE (ASW_CLEARIMAGESTORAGE_PACKETID & (0x00FF))

/* types-------------------------------------------------------------*/
//enumerations
typedef enum _ASW_EnumPktType_t
{
  ASW_PKT_TELEMETRY=0,
  ASW_PKT_TELECOMMAND=1,
  ASW_PKT_NB=2
} ASW_EnumPktType_t;

typedef enum _ASW_EnumBoolean_t
{
  ASW_BOL_FALSE=0,
  ASW_BOL_TRUE=1,
  ASW_BOL_NB=2
} ASW_EnumBoolean_t;

typedef enum _ASW_EnumImageDownloadAlgorithm_t
{
  ASW_COMP_NULL=0,
  ASW_COMP_NB=1
} ASW_EnumImageDownloadAlgorithm_t;

typedef enum _ASW_EnumApid_t
{
  ASW_APID_SUPERVISOR=32,
  ASW_APID_APPLICATIONSOFTWARE=33,
  ASW_APID_CAMERAIF=3,
  ASW_APID_OBCIF=35,
  ASW_APID_FRONTEND=100,
  ASW_APID_NB=5
} ASW_EnumApid_t;

typedef enum _ASW_EnumFid_t
{
  ASW_FID_OK=0,
  ASW_FID_INVALID_PLENGTH=1,
  ASW_FID_ILLEGAL_PUS_VERSION=2,
  ASW_FID_CS_DISCREP=3,
  ASW_FID_ILLEGAL_P_TYPE=4,
  ASW_FID_LENGTH_DISCREP=5,
  ASW_FID_INVALID_PARAMETER_VALUE=6,
  ASW_FID_BUSY=7,
  ASW_FID_NB=8
} ASW_EnumFid_t;

typedef enum _ASW_EnumHkReportId_t
{
  ASW_HKID_ALL=0,
  ASW_HKID_HEART_BEAT=1,
  ASW_HKID_CAM_STATUS=2,
  ASW_HKID_NB=3
} ASW_EnumHkReportId_t;

typedef enum _ASW_EnumEventId_t
{
  ASW_EID_MODE_CHANGE=0,
  ASW_EID_SEQUENCE_START=1,
  ASW_EID_SEQUENCE_END=2,
  ASW_EID_SEQUENCE_ABORT=3,
  ASW_EID_STORAGE_FAILURE=4,
  ASW_EID_DEATH_REPORT=5,
  ASW_EID_IMAGE_DISCARDED=6,
  ASW_EID_SAVE_IMAGE=7,
  ASW_EID_SAVE_IMAGE_FAILED=8,
  ASW_EID_NB=9
} ASW_EnumEventId_t;

typedef enum _ASW_EnumRebootReason_t
{
  ASW_RS_UNKNOWN=0,
  ASW_RS_COMMAND=1,
  ASW_RS_POWER_ON=2,
  ASW_RS_SW_ERROR=3,
  ASW_RS_NB=4
} ASW_EnumRebootReason_t;

typedef enum _ASW_EnumFunctionId_t
{
  ASW_FUN_REBOOT_BOARD=0,
  ASW_FUN_RESET_SOFTWARE=1,
  ASW_FUN_ACTIVATE_CAMERA_WAC=2,
  ASW_FUN_ACTIVATE_CAMERA_NAC=3,
  ASW_FUN_DEACTIVATE_CAMERA_WAC=4,
  ASW_FUN_DEACTIVATE_CAMERA_NAC=5,
  ASW_FUN_TAKE_PICTURE_WAC=6,
  ASW_FUN_TAKE_PICTURE_NAC=7,
  ASW_FUN_DOWNLOAD_PICTURES=8,
  ASW_FUN_START_PICTURE_SEQUENCE_WAC=9,
  ASW_FUN_START_PICTURE_SEQUENCE_NAC=10,
  ASW_FUN_START_LANDING_PICTURE_SEQUENCE_WAC=11,
  ASW_FUN_START_LANDING_PICTURE_SEQUENCE_NAC=12,
  ASW_FUN_MODE_SAFE=13,
  ASW_FUN_MODE_FLYBY=14,
  ASW_FUN_MODE_ALIVENESS=15,
  ASW_FUN_MODE_LANDING=16,
  ASW_FUN_NB=17
} ASW_EnumFunctionId_t;

typedef enum _ASW_EnumCameraId_t
{
  ASW_CAM_WAC=0,
  ASW_CAM_NAC=1,
  ASW_CAM_NB=2
} ASW_EnumCameraId_t;

typedef enum _ASW_EnumMode_t
{
  ASW_MODE_SAFE=0,
  ASW_MODE_ALIVENESS=1,
  ASW_MODE_FLYBY=2,
  ASW_MODE_LANDING=3,
  ASW_MODE_NB=4
} ASW_EnumMode_t;

typedef enum _ASW_EnumExposureStep_t
{
  ASW_EXST_10us=0,
  ASW_EXST_1ms=1,
  ASW_EXST_NB=2
} ASW_EnumExposureStep_t;

typedef enum _ASW_EnumPgaGain_t
{
  ASW_PG_X1=0,
  ASW_PG_X1_2=1,
  ASW_PG_X1_4=2,
  ASW_PG_X1_6=3,
  ASW_PG_NB=4
} ASW_EnumPgaGain_t;

typedef enum _ASW_EnumSequenceParameterId_t
{
  ASW_PAID_FLYBY_START_NA_S=0,
  ASW_PAID_FLYBY_START_WA_S=1,
  ASW_PAID_FLYBY_RATE_NA_S=2,
  ASW_PAID_FLYBY_RATE_WA_S=3,
  ASW_PAID_FLYBY_PICTURES_NO_NA=4,
  ASW_PAID_FLYBY_PICTURES_NO_WA=5,
  ASW_PAID_ALIVENESS_START_NA_S=6,
  ASW_PAID_ALIVENESS_START_WA_S=7,
  ASW_PAID_ALIVENESS_RATE_NA_S=8,
  ASW_PAID_ALIVENESS_RATE_WA_S=9,
  ASW_PAID_ALIVENESS_PICTURES_NO_NA=10,
  ASW_PAID_ALIVENESS_PICTURES_NO_WA=11,
  ASW_PAID_LANDING_START_NA_S=12,
  ASW_PAID_LANDING_START_WA_S=13,
  ASW_PAID_LANDING_START_RATE_NA_S=14,
  ASW_PAID_LANDING_START_RATE_WA_S=15,
  ASW_PAID_LANDING_END_RATE_RATE_NA_S=16,
  ASW_PAID_LANDING_END_RATE_RATE_WA_S=17,
  ASW_PAID_LANDING_PICTURES_NO_NA=18,
  ASW_PAID_LANDING_PICTURES_NO_WA=19,
  ASW_PAID_NB=20
} ASW_EnumSequenceParameterId_t;


//structures
typedef struct __attribute__((packed)) _ASW_UnexpectedValueUint16_t_
{
  uint16_t expectedValue;
  uint16_t foundValue;
} ASW_UnexpectedValueUint16_t;

typedef struct __attribute__((packed)) _ASW_InvalidParameterValue_t_
{
  uint16_t parameterCounter;
} ASW_InvalidParameterValue_t;

typedef struct __attribute__((packed)) _ASW_HkHeartBeat_t_
{
  uint32_t upTime;
  uint32_t onboardTime;
  uint8_t mode;
  uint8_t aplicationSwStatus;
  uint8_t obcIfStatus;
  uint8_t camIfStatus;
  uint8_t camNaPower;
  uint8_t camWaPower;
  uint8_t camNaStatus;
  uint8_t camWaStatus;
  uint16_t processesNo;
  uint32_t freeMemory;
  uint32_t freeSpace;
  float32_t cpuLoad;
} ASW_HkHeartBeat_t;

typedef struct __attribute__((packed)) _ASW_HkCamStatus_t_
{
  uint8_t bufferedNo;
  uint16_t storedNo;
  uint16_t downloadedNo;
  uint16_t wacTm1_1No;
  uint16_t wacTm1_2No;
  uint16_t wacTm1_7No;
  uint16_t wacTm1_8No;
  uint16_t wacTm3_25No;
  uint16_t wacSentCommandsNo;
  uint16_t wacReceivedImagesNo;
  float32_t wacTemperature;
  uint16_t nacTm1_1No;
  uint16_t nacTm1_2No;
  uint16_t nacTm1_7No;
  uint16_t nacTm1_8No;
  uint16_t nacTm3_25No;
  uint16_t nacSentCommandsNo;
  uint16_t nacReceivedImagesNo;
  float32_t nacTemperature;
} ASW_HkCamStatus_t;

typedef struct __attribute__((packed)) _ASW_DeathReport_t_
{
  uint32_t bootCounter;
  uint8_t rebootReason;
} ASW_DeathReport_t;

typedef struct __attribute__((packed)) _ASW_FunctionId_t_
{
  uint16_t functionId;
} ASW_FunctionId_t;

typedef struct __attribute__((packed)) _ASW_Mode_t_
{
  uint8_t mode;
} ASW_Mode_t;

typedef struct __attribute__((packed)) _ASW_ApidStructure_t_
{
  uint16_t apid;
} ASW_ApidStructure_t;

typedef struct __attribute__((packed)) _ASW_CameraIdStructure_t_
{
  uint8_t cameraId;
} ASW_CameraIdStructure_t;

typedef struct __attribute__((packed)) _ASW_TakePicture_t_
{
  uint8_t storeId;
} ASW_TakePicture_t;

typedef struct __attribute__((packed)) _ASW_DownloadPictures_t_
{
  uint8_t numberOfImages;
  uint8_t isDeleteImages;
  uint8_t compressionAlgorithm;
} ASW_DownloadPictures_t;

typedef struct __attribute__((packed)) _ASW_PictureSequence_t_
{
  uint32_t timeToWaitBeforeStart;
  uint32_t timeBetweenPictures;
  uint16_t numberOfPictures;
} ASW_PictureSequence_t;

typedef struct __attribute__((packed)) _ASW_LandingPictureSequence_t_
{
  uint32_t timeToWaitBeforeStart;
  uint32_t startTimeBetweenPictures;
  uint32_t endTimeBetweenPictures;
  uint32_t duration;
} ASW_LandingPictureSequence_t;


//packets
typedef struct __attribute__((packed)) _ASW_SuccessReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  PUS_AcceptanceReport_t pusAcceptanceReport;
} ASW_SuccessReport_t;

typedef struct __attribute__((packed)) _ASW_FailReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  PUS_AcceptanceReport_t pusAcceptanceReport;
  uint16_t failureId;
  union
  {
   ASW_UnexpectedValueUint16_t UnexpectedValueUint16;
   ASW_InvalidParameterValue_t InvalidParameterValue;
  }failureInfo;
} ASW_FailReport_t;

typedef struct __attribute__((packed)) _ASW_SuccessExecutionReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  PUS_AcceptanceReport_t pusAcceptanceReport;
} ASW_SuccessExecutionReport_t;

typedef struct __attribute__((packed)) _ASW_FailExecutionReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  PUS_AcceptanceReport_t pusAcceptanceReport;
  uint16_t failureId;
  union
  {
   ASW_UnexpectedValueUint16_t UnexpectedValueUint16;
   ASW_InvalidParameterValue_t InvalidParameterValue;
  }failureInfo;
} ASW_FailExecutionReport_t;

typedef struct __attribute__((packed)) _ASW_HkReportEnable_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t numberOfRequests;
  uint16_t structureId;
} ASW_HkReportEnable_t;

typedef struct __attribute__((packed)) _ASW_HkReportDisable_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t numberOfRequests;
  uint16_t structureId;
} ASW_HkReportDisable_t;

typedef struct __attribute__((packed)) _ASW_HkReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t structureId;
  union
  {
   ASW_HkHeartBeat_t HkHeartBeat;
   ASW_HkCamStatus_t HkCamStatus;
  }hkData;
} ASW_HkReport_t;

typedef struct __attribute__((packed)) _ASW_HkGenerate_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t numberOfRequests;
  uint16_t structureId;
} ASW_HkGenerate_t;

typedef struct __attribute__((packed)) _ASW_HkChangePeriod_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t numberOfRequests;
  uint16_t structureId;
  uint16_t collectionInterval;
} ASW_HkChangePeriod_t;

typedef struct __attribute__((packed)) _ASW_EventInformative_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t eventId;
  union
  {
   ASW_Mode_t Mode;
   ASW_FunctionId_t FunctionId;
   ASW_DeathReport_t DeathReport;
  }eventInfo;
} ASW_EventInformative_t;

typedef struct __attribute__((packed)) _ASW_EventLowSeverity_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t eventId;
  union
  {
   ASW_Mode_t Mode;
   ASW_FunctionId_t FunctionId;
   ASW_DeathReport_t DeathReport;
  }eventInfo;
} ASW_EventLowSeverity_t;

typedef struct __attribute__((packed)) _ASW_EventMediumSeverity_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t eventId;
  union
  {
   ASW_Mode_t Mode;
   ASW_FunctionId_t FunctionId;
   ASW_DeathReport_t DeathReport;
  }eventInfo;
} ASW_EventMediumSeverity_t;

typedef struct __attribute__((packed)) _ASW_EventHighSeverity_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t eventId;
  union
  {
   ASW_Mode_t Mode;
   ASW_FunctionId_t FunctionId;
   ASW_DeathReport_t DeathReport;
  }eventInfo;
} ASW_EventHighSeverity_t;

typedef struct __attribute__((packed)) _ASW_ExecuteFunction_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint16_t functionId;
  union
  {
   ASW_ApidStructure_t ApidStructure;
   ASW_TakePicture_t TakePicture;
   ASW_DownloadPictures_t DownloadPictures;
   ASW_PictureSequence_t PictureSequence;
   ASW_LandingPictureSequence_t LandingPictureSequence;
  }functionParameters;
} ASW_ExecuteFunction_t;

typedef struct __attribute__((packed)) _ASW_StopFunction_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint16_t functionId;
} ASW_StopFunction_t;

typedef struct __attribute__((packed)) _ASW_UpdateTime_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint32_t time;
  uint32_t unused;
} ASW_UpdateTime_t;

typedef struct __attribute__((packed)) _ASW_ConnectionTest_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint16_t apid;
} ASW_ConnectionTest_t;

typedef struct __attribute__((packed)) _ASW_ConnectionReport_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint16_t apid;
} ASW_ConnectionReport_t;

typedef struct __attribute__((packed)) _ASW_SetMode_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t mode;
} ASW_SetMode_t;

typedef struct __attribute__((packed)) _ASW_SetPictureParameters_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t cameraId;
  uint8_t exposureStep;
  uint32_t exposure1;
  uint32_t exposure2;
  uint8_t autoExposureEnabled;
  uint8_t hdrEnabled;
  uint8_t testPatern;
  uint8_t binning;
  uint8_t compression;
  uint16_t thresholdL;
  uint16_t thresholdH;
} ASW_SetPictureParameters_t;

typedef struct __attribute__((packed)) _ASW_SetCameraParameters_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t cameraId;
  uint16_t offset;
  uint8_t adcGain;
  uint8_t isPgaGainDoubled;
  uint8_t pgaGain;
  uint8_t voltageRamp;
} ASW_SetCameraParameters_t;

typedef struct __attribute__((packed)) _ASW_SetSequenceParameters_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t parameterId;
  uint32_t parameterValue;
} ASW_SetSequenceParameters_t;

typedef struct __attribute__((packed)) _ASW_SaveParameters_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
} ASW_SaveParameters_t;

typedef struct __attribute__((packed)) _ASW_ClearParameters_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
} ASW_ClearParameters_t;

typedef struct __attribute__((packed)) _ASW_ImageMetadata_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint32_t bootCounter;
  uint32_t acquisitionTimeStamp;
  uint8_t cameraId;
  uint8_t storeId;
  uint8_t exposureStep;
  uint32_t exposure1;
  uint32_t exposure2;
  uint8_t autoExposureEnabled;
  uint8_t hdrEnabled;
  uint8_t testPatern;
  uint8_t binning;
  uint8_t compression;
  uint16_t thresholdL;
  uint16_t thresholdH;
  uint16_t offset;
  uint8_t isPgaGainDoubled;
  uint8_t pgaGain;
  uint8_t voltageRamp;
  uint32_t withinThresholdPixelsNo;
  uint16_t withinThresholdLinesNo;
  float32_t tenengradNorm;
  float32_t edgeCntNorm;
  float32_t dynRangeNorm;
  float32_t blkCntNorm;
  float32_t whtCntNorm;
  float32_t score;
} ASW_ImageMetadata_t;

typedef struct __attribute__((packed)) _ASW_ImageSegment_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint32_t bootCounter;
  uint32_t acquisitionTimeStamp;
  uint8_t cameraId;
  uint16_t line;
  uint16_t startRow;
  uint16_t numberOfPixels;
  uint8_t pixel[1024];
} ASW_ImageSegment_t;

typedef struct __attribute__((packed)) _ASW_GetSequenceParametersValue_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
  uint8_t parameterId;
} ASW_GetSequenceParametersValue_t;

typedef struct __attribute__((packed)) _ASW_SequenceParametersValue_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TmSecondaryHeader_t pusTmSecondaryHeader;
  uint8_t parameterId;
  uint32_t parameterValue;
} ASW_SequenceParametersValue_t;

typedef struct __attribute__((packed)) _ASW_ClearImageStorage_t_
{
  CCSDS_PrimaryHeader_t ccsdsPrimaryHeader;
  PUS_TcSecondaryHeader_t pusTcSecondaryHeader;
} ASW_ClearImageStorage_t;


void ASWF_FillSuccessReport(ASW_SuccessReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, PUS_AcceptanceReport_t *pusAcceptanceReport);
void ASWF_FillFailReport(ASW_FailReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, PUS_AcceptanceReport_t *pusAcceptanceReport, ASW_EnumFid_t failureId, void *failureInfo, uint16_t failureInfoNb);
void ASWF_FillSuccessExecutionReport(ASW_SuccessExecutionReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, PUS_AcceptanceReport_t *pusAcceptanceReport);
void ASWF_FillFailExecutionReport(ASW_FailExecutionReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, PUS_AcceptanceReport_t *pusAcceptanceReport, ASW_EnumFid_t failureId, void *failureInfo, uint16_t failureInfoNb);
void ASWF_FillHkReportEnable(ASW_HkReportEnable_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, uint8_t numberOfRequests, ASW_EnumHkReportId_t structureId);
void ASWF_FillHkReportDisable(ASW_HkReportDisable_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, uint8_t numberOfRequests, ASW_EnumHkReportId_t structureId);
void ASWF_FillHkReport(ASW_HkReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumHkReportId_t structureId, void *hkData, uint16_t hkDataNb);
void ASWF_FillHkGenerate(ASW_HkGenerate_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, uint8_t numberOfRequests, ASW_EnumHkReportId_t structureId);
void ASWF_FillHkChangePeriod(ASW_HkChangePeriod_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, uint8_t numberOfRequests, ASW_EnumHkReportId_t structureId, uint16_t collectionInterval);
void ASWF_FillEventInformative(ASW_EventInformative_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumEventId_t eventId, void *eventInfo, uint16_t eventInfoNb);
void ASWF_FillEventLowSeverity(ASW_EventLowSeverity_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumEventId_t eventId, void *eventInfo, uint16_t eventInfoNb);
void ASWF_FillEventMediumSeverity(ASW_EventMediumSeverity_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumEventId_t eventId, void *eventInfo, uint16_t eventInfoNb);
void ASWF_FillEventHighSeverity(ASW_EventHighSeverity_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumEventId_t eventId, void *eventInfo, uint16_t eventInfoNb);
void ASWF_FillExecuteFunction(ASW_ExecuteFunction_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumFunctionId_t functionId, void *functionParameters, uint16_t functionParametersNb);
void ASWF_FillStopFunction(ASW_StopFunction_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumFunctionId_t functionId);
void ASWF_FillUpdateTime(ASW_UpdateTime_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, uint32_t time, uint32_t unused);
void ASWF_FillConnectionTest(ASW_ConnectionTest_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumApid_t apid);
void ASWF_FillConnectionReport(ASW_ConnectionReport_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumApid_t apid);
void ASWF_FillSetMode(ASW_SetMode_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumMode_t mode);
void ASWF_FillSetPictureParameters(ASW_SetPictureParameters_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumCameraId_t cameraId, ASW_EnumExposureStep_t exposureStep, uint32_t exposure1, uint32_t exposure2, ASW_EnumBoolean_t autoExposureEnabled, ASW_EnumBoolean_t hdrEnabled, uint8_t testPatern, ASW_EnumBoolean_t binning, ASW_EnumBoolean_t compression, uint16_t thresholdL, uint16_t thresholdH);
void ASWF_FillSetCameraParameters(ASW_SetCameraParameters_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumCameraId_t cameraId, uint16_t offset, uint8_t adcGain, ASW_EnumBoolean_t isPgaGainDoubled, ASW_EnumPgaGain_t pgaGain, uint8_t voltageRamp);
void ASWF_FillSetSequenceParameters(ASW_SetSequenceParameters_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumSequenceParameterId_t parameterId, uint32_t parameterValue);
void ASWF_FillSaveParameters(ASW_SaveParameters_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader);
void ASWF_FillClearParameters(ASW_ClearParameters_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader);
void ASWF_FillImageMetadata(ASW_ImageMetadata_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, uint32_t bootCounter, uint32_t acquisitionTimeStamp, ASW_EnumCameraId_t cameraId, uint8_t storeId, ASW_EnumExposureStep_t exposureStep, uint32_t exposure1, uint32_t exposure2, ASW_EnumBoolean_t autoExposureEnabled, ASW_EnumBoolean_t hdrEnabled, uint8_t testPatern, ASW_EnumBoolean_t binning, ASW_EnumBoolean_t compression, uint16_t thresholdL, uint16_t thresholdH, uint16_t offset, ASW_EnumBoolean_t isPgaGainDoubled, ASW_EnumPgaGain_t pgaGain, uint8_t voltageRamp, uint32_t withinThresholdPixelsNo, uint16_t withinThresholdLinesNo, float32_t tenengradNorm, float32_t edgeCntNorm, float32_t dynRangeNorm, float32_t blkCntNorm, float32_t whtCntNorm, float32_t score);
void ASWF_FillImageSegment(ASW_ImageSegment_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, uint32_t bootCounter, uint32_t acquisitionTimeStamp, ASW_EnumCameraId_t cameraId, uint16_t line, uint16_t startRow, uint16_t numberOfPixels, uint8_t *pixel);
void ASWF_FillGetSequenceParametersValue(ASW_GetSequenceParametersValue_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader, ASW_EnumSequenceParameterId_t parameterId);
void ASWF_FillSequenceParametersValue(ASW_SequenceParametersValue_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TmSecondaryHeader_t *pusTmSecondaryHeader, ASW_EnumSequenceParameterId_t parameterId, uint32_t parameterValue);
void ASWF_FillClearImageStorage(ASW_ClearImageStorage_t *target, CCSDS_PrimaryHeader_t *ccsdsPrimaryHeader, PUS_TcSecondaryHeader_t *pusTcSecondaryHeader);

uint16_t ASWF_GetSizeForEnumPktType(ASW_EnumPktType_t valueEnumPktType);
uint16_t ASWF_GetSizeForEnumBoolean(ASW_EnumBoolean_t valueEnumBoolean);
uint16_t ASWF_GetSizeForEnumImageDownloadAlgorithm(ASW_EnumImageDownloadAlgorithm_t valueEnumImageDownloadAlgorithm);
uint16_t ASWF_GetSizeForEnumApid(ASW_EnumApid_t valueEnumApid);
uint16_t ASWF_GetSizeForEnumFid(ASW_EnumFid_t valueEnumFid);
uint16_t ASWF_GetSizeForEnumHkReportId(ASW_EnumHkReportId_t valueEnumHkReportId);
uint16_t ASWF_GetSizeForEnumEventId(ASW_EnumEventId_t valueEnumEventId);
uint16_t ASWF_GetSizeForEnumRebootReason(ASW_EnumRebootReason_t valueEnumRebootReason);
uint16_t ASWF_GetSizeForEnumFunctionId(ASW_EnumFunctionId_t valueEnumFunctionId);
uint16_t ASWF_GetSizeForEnumCameraId(ASW_EnumCameraId_t valueEnumCameraId);
uint16_t ASWF_GetSizeForEnumMode(ASW_EnumMode_t valueEnumMode);
uint16_t ASWF_GetSizeForEnumExposureStep(ASW_EnumExposureStep_t valueEnumExposureStep);
uint16_t ASWF_GetSizeForEnumPgaGain(ASW_EnumPgaGain_t valueEnumPgaGain);
uint16_t ASWF_GetSizeForEnumSequenceParameterId(ASW_EnumSequenceParameterId_t valueEnumSequenceParameterId);

#endif
