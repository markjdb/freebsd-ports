--- ./buttonlist.h.orig	2000-01-25 17:41:32.000000000 +0100
+++ ./buttonlist.h	2013-12-28 11:39:15.000000000 +0100
@@ -16,7 +16,7 @@
 
 	void Add_Button(Uint16 x, Uint16 y, Uint16 width, Uint16 height, 
 						void (*callback)(void)) {
-		struct button *belem;
+		button *belem;
 		
 		for ( belem=&button_list; belem->next; belem=belem->next );
 		belem->next = new button;
@@ -30,7 +30,7 @@
 	}
 
 	void Activate_Button(Uint16 x, Uint16 y) {
-		struct button *belem;
+		button *belem;
 
 		for ( belem=button_list.next; belem; belem=belem->next ) {
 			if ( (x >= belem->x1) && (x <= belem->x2) &&
@@ -42,7 +42,7 @@
 	}
 
 	void Delete_Buttons(void) {
-		struct button *belem, *btemp;
+		button *belem, *btemp;
 
 		for ( belem=button_list.next; belem; ) {
 			btemp = belem;
