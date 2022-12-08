TAG_SHIFT = 9
INDEX_AND = 0x1fc
INDEX_SHIFT = 2
OFFSET_AND = 0x3
BIN_HEADER = "0b"
Cache = []

def Part_Address(Address):
    return hex(Address>>TAG_SHIFT), (Address&INDEX_AND)>>INDEX_SHIFT, bin(Address&OFFSET_AND)

def add_To_Cache(Address_List):
    # global cache
    for each in range(0,len(Address_List)):
        if Address_List[each]>>TAG_SHIFT == 0x78:
            Push_Instruction(Address_List[each:])
            
def Push_Instruction(Address_List):
    Times = Get_Next_Instruction(Address_List[1:])
    Pusher = Address_List[0] 
    Times = Pusher - Times
    for i in range(0,Times):
        Push_Address(Pusher)
        pusher+=1

def Push_Address( Address ):
    Cache.append()

def Get_Next_Instruction(Address_List):
    for each in range(0,len(Address_List)):
        if Address_List[each]>>TAG_SHIFT == 0x78:
            return each

def Push_to_Cache(Address):
    pass
