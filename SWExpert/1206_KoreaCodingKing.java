package Test;

import java.util.*;
public class SW1206 {
	public static void main(String[] args) {
		Random rd=new Random();
		int[] buildings=new int[1001];
		int count=0;
		int[] compare=new int[4];
		int max=0;
		
		buildings[0]=0;
		buildings[1]=0;
		buildings[buildings.length-1]=0;
		buildings[buildings.length-2]=0;
		
		for(int i=2;i<buildings.length-2;i++) {
			buildings[i]=rd.nextInt(255);
		}
		
		for(int i=2;i<buildings.length-2;i++) {
			if(buildings[i]>buildings[i-1] && buildings[i]>buildings[i-2] &&
					buildings[i]>buildings[i+1] && buildings[i]>buildings[i+2]) {
				compare[0]=buildings[i-1];
				compare[1]=buildings[i-2];
				compare[2]=buildings[i+1];
				compare[3]=buildings[i+2];
				for(int j=0;j<3;j++) {
					if(compare[j]>=compare[j+1]) {
						max=compare[j];
					}
				}
				count+=buildings[i]-max;
//						 if(buildings[i-1]>=buildings[i-2] && buildings[i-1]>=buildings[i+1] && 
//								 buildings[i-1]>=buildings[i+2]) {
//							 count+=buildings[i]-buildings[i-1];
//						 }else if(buildings[i-2]>=buildings[i-1] && buildings[i-2]>=buildings[i+1] && 
//								 buildings[i-2]>=buildings[i+2]){
//							 count+=buildings[i]-buildings[i-2];
//						 }else if(buildings[i+1]>=buildings[i-1] && buildings[i+1]>=buildings[i-2] && 
//								 buildings[i+1]>=buildings[i+2]) {
//							 count+=buildings[i]-buildings[i+1];
//						 }else {
//							 count+=buildings[i]-buildings[i+2];
//						 }
			}
		}
		
		System.out.println(count);
	}
}
