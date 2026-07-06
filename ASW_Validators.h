/*******************************************************************************/
/* Copyright XXXXXXXXX 1998-YYYY                                               */
/*                                                                             */
/* xxxxxxxx@xxxxx.xxx                                                          */
/*******************************************************************************/

#ifndef ASWV_Validators_H
#define ASWV_Validators_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes-------------------------------------------------------------*/
#include <myTypes.h>
#include <LIB_Crc.h>

/* component includes-------------------------------------------------------------*/
#include <ASW_Fillers.h>
#include <ASW_ValidatorsUser.h>

/* macros-------------------------------------------------------------*/
/* none */

/* macros-------------------------------------------------------------*/
/* none */

/* types-------------------------------------------------------------*/
/* none */

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions-------------------------------------------------------------*/
bool_t ASWV_ValidatePacket(uint8_t *packetRaw, uint16_t totalLength, void *structuredData, uint16_t outputNb, uint16_t *packetId, uint16_t *failureId, uint8_t *failureInfo);
ASWV_ValidatorFunction_t ASWVU_ValidateSuccessReport;
ASWV_ValidatorFunction_t ASWVU_ValidateFailReport;
ASWV_ValidatorFunction_t ASWVU_ValidateSuccessExecutionReport;
ASWV_ValidatorFunction_t ASWVU_ValidateFailExecutionReport;
ASWV_ValidatorFunction_t ASWVU_ValidateHkReportEnable;
ASWV_ValidatorFunction_t ASWVU_ValidateHkReportDisable;
ASWV_ValidatorFunction_t ASWVU_ValidateHkReport;
ASWV_ValidatorFunction_t ASWVU_ValidateHkGenerate;
ASWV_ValidatorFunction_t ASWVU_ValidateHkChangePeriod;
ASWV_ValidatorFunction_t ASWVU_ValidateEventInformative;
ASWV_ValidatorFunction_t ASWVU_ValidateEventLowSeverity;
ASWV_ValidatorFunction_t ASWVU_ValidateEventMediumSeverity;
ASWV_ValidatorFunction_t ASWVU_ValidateEventHighSeverity;
ASWV_ValidatorFunction_t ASWVU_ValidateExecuteFunction;
ASWV_ValidatorFunction_t ASWVU_ValidateStopFunction;
ASWV_ValidatorFunction_t ASWVU_ValidateUpdateTime;
ASWV_ValidatorFunction_t ASWVU_ValidateConnectionTest;
ASWV_ValidatorFunction_t ASWVU_ValidateConnectionReport;
ASWV_ValidatorFunction_t ASWVU_ValidateSetMode;
ASWV_ValidatorFunction_t ASWVU_ValidateSetPictureParameters;
ASWV_ValidatorFunction_t ASWVU_ValidateSetCameraParameters;
ASWV_ValidatorFunction_t ASWVU_ValidateSetSequenceParameters;
ASWV_ValidatorFunction_t ASWVU_ValidateSaveParameters;
ASWV_ValidatorFunction_t ASWVU_ValidateClearParameters;
ASWV_ValidatorFunction_t ASWVU_ValidateImageMetadata;
ASWV_ValidatorFunction_t ASWVU_ValidateImageSegment;
ASWV_ValidatorFunction_t ASWVU_ValidateGetSequenceParametersValue;
ASWV_ValidatorFunction_t ASWVU_ValidateSequenceParametersValue;
ASWV_ValidatorFunction_t ASWVU_ValidateClearImageStorage;

#endif
