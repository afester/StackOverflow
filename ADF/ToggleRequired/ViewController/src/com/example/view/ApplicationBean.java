package com.example.view;

import java.util.ArrayList;
import java.util.List;

import javax.faces.model.SelectItem;

public class ApplicationBean {
    public List getMyItems() {
        List<SelectItem> result = new ArrayList<SelectItem>();

        result.add(new SelectItem("1", "Sun"));
        result.add(new SelectItem("2", "Moon"));
        result.add(new SelectItem("3", "Earth"));
        
        return result;
    }
}
