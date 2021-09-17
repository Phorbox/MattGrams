package main;

import hashdb.HashFile;
import hashdb.HashHeader;
import hashdb.Vehicle;
import misc.ReturnCodes;
import main.Main;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class StudentFunctions {
    /**
     * hashCreate
     * This funcAon creates a hash file containing onlybinaryHashFile = new RandomAccessFile(fileName,"r"); the HashHeader record.
     * • If the file already exists, return RC_FILE_EXISTS
     * • Create the binary file by opening it.
     * • Write the HashHeader record to the file at RBN 0.
     * • close the file.
     * • return RC_OK.
     */
    public static int hashCreate(String fileName, HashHeader hashHeader) {
        RandomAccessFile binaryHashFile;

        if (hashBinaryFileExists(fileName)) {
            return ReturnCodes.RC_FILE_EXISTS;
        }


        try {
            binaryHashFile = new RandomAccessFile(fileName, "rw");
            binaryHashFile.write(hashHeader.toByteArray());
            binaryHashFile.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
        return ReturnCodes.RC_OK;
    }

    private static boolean hashBinaryFileExists(String fileName) {
        boolean fileDoesExist = true;
        RandomAccessFile binaryHashFile;
        try {
            binaryHashFile = new RandomAccessFile(fileName, "r");
            binaryHashFile.close();
        } catch (IOException e) {
            fileDoesExist = false;
        }
        return fileDoesExist;
    }

    /**
     * hashOpen
     * This function opens an existing hash file which must contain a HashHeader record
     * , and sets the file member of hashFile
     * It returns the HashHeader record by setting the HashHeader member in hashFile
     * If it doesn't exist, return RC_FILE_NOT_FOUND.
     * Read the HashHeader record from file and return it through the parameter.
     * If the read fails, return RC_HEADER_NOT_FOUND.
     * return RC_OK
     */
    public static int hashOpen(String fileName, HashFile hashFile) {
        HashHeader header = new HashHeader();
        if (hashBinaryFileExists(fileName)) {
            return ReturnCodes.RC_FILE_NOT_FOUND;
        }
        byte[] headerBuffer = new byte[HashHeader.MAX_REC_SIZE];
        try {
            RandomAccessFile binaryHashFile = new RandomAccessFile(fileName, "rw");
            binaryHashFile.read(headerBuffer);
            header.fromByteArray(headerBuffer);
            hashFile.setHashHeader(header);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            return ReturnCodes.RC_HEADER_NOT_FOUND;
        }

        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleInsert
     * This function inserts a vehicle into the specified file.
     * Determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If that location doesn't exist
     * OR the record at that location has a blank vehicleId (i.e., empty string):
     * THEN Write this new vehicle record at that location using writeRec.
     * If that record exists and that vehicle's szVehicleId matches, return RC_REC_EXISTS.
     * (Do not update it.)
     * Otherwise, return RC_SYNONYM. a SYNONYM is the same thing as a HASH COLLISION
     * Note that in program #2, we will actually insert synonyms.
     */
    public static int vehicleInsert(HashFile hashFile, Vehicle vehicle) {
        int tempMaxHash = getMaxHashFromHashFile(hashFile);
        int hashedID = Main.hash(vehicle.getVehicleId(),tempMaxHash);



        return ReturnCodes.RC_SYNONYM;
    }

    public static int getMaxHashFromHashFile(HashFile hashFile){
        HashHeader tempHeader = hashFile.getHashHeader();

        return tempHeader.getMaxHash();
    }

    /**
     * readRec(
     * This function reads a record at the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Read that record and return it through the vehicle parameter.
     * If the location is not found, return RC_LOC_NOT_FOUND.  Otherwise, return RC_OK.
     * Note: if the location is found, that does NOT imply that a vehicle
     * was written to that location.  Why?
     */
    public static int readRec(HashFile hashFile, int rbn, Vehicle vehicle) {


        return ReturnCodes.RC_LOC_NOT_FOUND;
    }

    /**
     * writeRec
     * This function writes a record to the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Write that record to the file.
     * If the write fails, return RC_LOC_NOT_WRITTEN.
     * Otherwise, return RC_OK.
     */
    public static int writeRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        return ReturnCodes.RC_LOC_NOT_WRITTEN;
    }

    /**
     * vehicleRead
     * This function reads the specified vehicle by its vehicleId.
     * Since the vehicleId was provided,
     * determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If the vehicle at that location matches the specified vehicleId,
     * return the vehicle via the parameter and return RC_OK.
     * Otherwise, return RC_REC_NOT_FOUND
     */
    public static int vehicleRead(HashFile hashFile, int rbn, Vehicle vehicle) {
        return ReturnCodes.RC_REC_NOT_FOUND;
    }
}
