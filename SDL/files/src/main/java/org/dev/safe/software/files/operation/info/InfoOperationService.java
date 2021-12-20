package org.dev.safe.software.files.operation.info;

import lombok.NonNull;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.operation.info.model.InfoOperationResult;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.util.ArrayList;
import java.util.List;

@Slf4j
@Service
public class InfoOperationService {

    @NonNull
    public List<InfoOperationResult> getDrivesInfo() {
        var result = new ArrayList<InfoOperationResult>();

        FileSystems.getDefault().getFileStores()
                .forEach(fs -> {
                            try {
                                result.add(InfoOperationResult.builder()
                                        .name(fs.name())
                                        .path(fs.toString().substring(0, fs.toString().indexOf(' ')))
                                        .usedSpace(fs.getUsableSpace())
                                        .totalSpace(fs.getTotalSpace())
                                        .fsType(fs.type())
                                        .build());
                            } catch (IOException e) {
                                log.error("Failed to get devices info. '{}'", e.getMessage(), e);
                            }
                        }
                );

        return result;
    }

}
