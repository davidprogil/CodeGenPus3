### Other Data Types

#### PUS_TmSecondaryHeader 
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: scTimeReferenceStatus type: uint8 - Fixed Value: 0
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- uint16_t messageTypeCounter;//per pid, per type/subtype, or 0 if not supported NOTS
- Name: destinationId type: uint16 - network address of TM issuer
- Name: time type: uint32 - time stamp of the TM
- Name: spare type: uint8 value ignored
 
#### PUS_TcSecondaryHeader
Data Fields:
- Name: version Type: uint 4 bits Fixed Value: 1
- Name: acknowledgementFlags Type: 4 bits, bit 3 = user requests successful acknowledgment bit 0 = user requests  successful end of execution
- Name: serviceType Type: uint8 (Higher Part of packet ID)
- Name: serviceSubType Type: uint8 (Lower Part of packet ID)
- Name: sourceId type: uint16 - network address of TC issuer
- Name: spare type: uint8 value ignored

### PUS_AcceptanceReport_t
Data Fields:
- Name: version Type: uint 3 bits Fixed Value: 1
- Name: packetType Type: 1 bit [EnumPktType](#enumpktype)
- Name: secondaryHeaderFlag Type: 1 bit Fixed Value: 1
- Name: sourceId Type: uint 11 bits- network address of TC issuer
- Name: sequenceFlags Type: 2 bits Always 0
- Name: packetSequenceCount: Type 14 bits - Sequence ID of the TC that is being responded to
	