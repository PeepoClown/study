package org.dev.safe.software.files.operation.xml;

import jakarta.xml.bind.JAXBContext;
import jakarta.xml.bind.Marshaller;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.model.SuccessResponse;
import org.dev.safe.software.files.operation.file.FileOperationService;
import org.dev.safe.software.files.operation.xml.model.XmlSerializableObject;
import org.eclipse.persistence.jaxb.JAXBContextFactory;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import java.io.File;

import static org.dev.safe.software.files.util.BuildUtils.buildFailResponse;

@Slf4j
@Service
@RequiredArgsConstructor
public class XmlOperationService {

    private final FileOperationService fileOperationService;

    @NonNull
    public CommonResponse createXml(@NonNull String path, @NonNull String data) {
        var creationResult = fileOperationService.createFile(path);
        if (!creationResult.isSuccess()) {
            return creationResult;
        }

        return fileOperationService.writeFile(path, data);
    }

    @NonNull
    public CommonResponse writeObjectToXml(@NonNull String path, @NonNull XmlSerializableObject object) {
        try {
            var creationResult = fileOperationService.createFile(path);
            if (!creationResult.isSuccess()) {
                return creationResult;
            }

            JAXBContext jaxbContext = JAXBContextFactory
                    .createContext(new Class[] {XmlSerializableObject.class}, null);
            Marshaller jaxbMarshaller = jaxbContext.createMarshaller();
            jaxbMarshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            jaxbMarshaller.marshal(object, ((SuccessResponse<File>)creationResult).getData());

            log.info("Success to serialize '{}' to xml and write it into '{}", object, path);
            return fileOperationService.readFile(path);
        } catch (Exception e) {
            log.error("Failed to write serialized object to xml. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse readXml(@NonNull String path) {
        return fileOperationService.readFile(path);
    }

    @NonNull
    public CommonResponse deleteXml(@NonNull String path) {
        return fileOperationService.deleteFile(path);
    }

}
