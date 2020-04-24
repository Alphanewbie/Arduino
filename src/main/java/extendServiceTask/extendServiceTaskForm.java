package extendServiceTask;

import org.activiti.designer.integration.annotation.Property;
import org.activiti.designer.integration.annotation.Runtime;
import org.activiti.designer.integration.servicetask.AbstractCustomServiceTask;
import org.activiti.designer.integration.servicetask.PropertyType;

@Runtime(javaDelegateClass="extendServiceTaskExecution")
public class extendServiceTaskForm extends AbstractCustomServiceTask {
	@Property(type = PropertyType.TEXT,displayName = "text", required =true)
	private String text;
	
	@Override
	public String contributeToPaletteDrawer() {
		return "paletteGroupName";
	}
	
	public String getName() {
		return "extendServiceTask";
	}
	
	@Override
		public String getSmallIconPath() {
		return "sensingIcon2.png";
	}
}
