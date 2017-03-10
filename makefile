include prorab.mk

this_name := mordatouch

this_srcs += $(call prorab-src-dir,src)

this_ldlibs += -lmordavokne-opengles2 -lstdc++

$(eval $(prorab-build-app))
