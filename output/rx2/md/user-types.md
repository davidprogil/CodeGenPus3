### Other Data Types

####PUS_TmSecondaryHeader 
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: scTimeReferenceStatus type: uint8 - Fixed Value: 0
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- uint16_t messageTypeCounter;//per pid, per type/subtype, or 0 if not supported NOTS
- Name: destinationId type: uint16 - network address of TM issuer
- Name: time type: uint32 - time stamp of the TM
- Name: spare type: uint8 value ignored
 
####PUS_TcSecondaryHeader
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: acknowledgementFlags Type: 4 bits, bit 3 = user requests successful acknowledgment bit 0 = user requests  successful end of execution
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- Name: sourceId type: uint16 - network address of TC issuer
- Name: spare type: uint8 value ignored