package com.example.view;

import javax.faces.context.FacesContext;
import javax.faces.event.ValueChangeEvent;

public class SessionBean {
    
    public SessionBean() {
        super();
    }
    
    private boolean skipInput = false;

    public boolean getSkipInput() {
        System.err.println("SessionBean::getSkipInput() =" + skipInput);
        return skipInput;
    }

    public void setSkipInput(boolean val) {
        System.err.println("SessionBean::setSkipInput(" + val + ")");
        skipInput = val;
    }
     
    public void toggleSkipInput(ValueChangeEvent vce) {
        System.err.println("SessionBean::toggleSkipInput(" + vce + ")");
        
        setSkipInput(Boolean.TRUE.equals(vce.getNewValue()));
        FacesContext.getCurrentInstance().renderResponse();
    }

    private String selected   = "";
    public String getSomeValue() {
        return selected;
    }
    public void setSomeValue(String val) {
        selected = val;
    }

}
