package(default_visibility = ["//visibility:public"])

licenses(["notice"])

filegroup(
    name = "license",
    srcs = ["LICENSE"],
)

cc_library(
	name = "util",
    srcs = [
	"base/int128.cc",
	"base/logging.cc",
	"base/stringprintf.cc",
	"base/strtoint.cc",
	"strings/ascii_ctype.cc",
	"strings/split.cc",
	"strings/stringprintf.cc",
	"strings/strutil.cc",
	"util/coding/coder.cc",
	"util/coding/varint.cc",
	"util/hash/hash.cc",
	"util/math/exactfloat/exactfloat.cc",
	"util/math/mathlimits.cc",
	"util/math/mathutil.cc",

	hdrs = [
	base/basictypes.h
	base/casts.h
	base/commandlineflags.h
	base/int128.h
	base/integral_types.h
	base/logging.h
	base/macros.h
	base/port.h
	base/scoped_ptr.h
	base/stl_decl.h
	base/stl_decl_msvc.h
	base/stl_decl_osx.h
	base/stringprintf.h
	base/strtoint.h
	base/template_util.h
	base/type_traits.h

	],
    copts = [
        "-Wall",
        "-Wwrite-strings",
        "-Woverloaded-virtual",
        "-Wno-sign-compare",
        "-DHASH_NAMESPACE=std",
        "-Wno-absolute-value",
        "-Wno-dynamic-class-memaccess",
        "-Wno-narrowing",
        "-Wno-deprecated",
        "-std=c++11",
    ],
    deps = [ "//external:gflags" ],
)

cc_library(
    name = "s2",
    srcs = [
        "upstream/s2/s1angle.cc",
        "upstream/s2/s1interval.cc",
        "upstream/s2/s2.cc",
        "upstream/s2/s2cap.cc",
        "upstream/s2/s2cell.cc",
        "upstream/s2/s2cellid.cc",
        "upstream/s2/s2cellunion.cc",
        "upstream/s2/s2edgeindex.cc",
        "upstream/s2/s2edgeutil.cc",
        "upstream/s2/s2latlng.cc",
        "upstream/s2/s2latlngrect.cc",
        "upstream/s2/s2loop.cc",
        "upstream/s2/s2pointregion.cc",
        "upstream/s2/s2polygon.cc",
        "upstream/s2/s2polygonbuilder.cc",
        "upstream/s2/s2polyline.cc",
        "upstream/s2/s2r2rect.cc",
        "upstream/s2/s2region.cc",
        "upstream/s2/s2regioncoverer.cc",
        "upstream/s2/s2regionintersection.cc",
        "upstream/s2/s2regionunion.cc",
    ],
    hdrs = [
		s2/r1interval.h",
		s2/s1angle.h",
		s2/s1interval.h",
		s2/s2cap.h",
		s2/s2cell.h",
		s2/s2cellid.h",
		s2/s2cellunion.h",
		s2/s2edgeindex.h",
		s2/s2edgeutil.h",
		s2/s2.h",
		s2/s2latlng.h",
		s2/s2latlngrect.h",
		s2/s2loop.h",
		s2/s2pointregion.h",
		s2/s2polygonbuilder.h",
		s2/s2polygon.h",
		s2/s2polyline.h",
		s2/s2r2rect.h",
		s2/s2regioncoverer.h",
		s2/s2region.h",
		s2/s2regionintersection.h",
		s2/s2regionunion.h",
	]
	copts = [
        "-Wall",
        "-Wwrite-strings",
        "-Woverloaded-virtual",
        "-Wno-sign-compare",
        "-DS2_USE_EXACTFLOAT",
        "-DHASH_NAMESPACE=std",
        "-Wno-absolute-value",
        "-Wno-dynamic-class-memaccess",
        "-Wno-deprecated",
        "-Wno-unused-local-typedefs",
        "-Wno-unused-but-set-variable",
        "-std=c++11",
        "-Ithird_party/s2/upstream",
    ],
    includes = ["upstream"],
    deps = [ ":base" ],
)


set(s2cellid_files
	s1angle.cc
	s2.cc
	s2cellid.cc
	s2latlng.cc
)

set(s2_files
	s1interval.cc
	s2cap.cc
	s2cell.cc
	s2cellunion.cc
	s2edgeindex.cc
	s2edgeutil.cc
	s2latlngrect.cc
	s2loop.cc
	s2pointregion.cc
	s2polygon.cc
	s2polygonbuilder.cc
	s2polyline.cc
	s2r2rect.cc
	s2region.cc
	s2regioncoverer.cc
	s2regionintersection.cc
	s2regionunion.cc
)

set(s2includes
	s2/r1interval.h
	s2/s1angle.h
	s2/s1interval.h
	s2/s2cap.h
	s2/s2cell.h
	s2/s2cellid.h
	s2/s2cellunion.h
	s2/s2edgeindex.h
	s2/s2edgeutil.h
	s2/s2.h
	s2/s2latlng.h
	s2/s2latlngrect.h
	s2/s2loop.h
	s2/s2pointregion.h
	s2/s2polygonbuilder.h
	s2/s2polygon.h
	s2/s2polyline.h
	s2/s2r2rect.h
	s2/s2regioncoverer.h
	s2/s2region.h
	s2/s2regionintersection.h
	s2/s2regionunion.h
)

set(s2includes_base
	base/basictypes.h
	base/casts.h
	base/commandlineflags.h
	base/int128.h
	base/integral_types.h
	base/logging.h
	base/macros.h
	base/port.h
	base/scoped_ptr.h
	base/stl_decl.h
	base/stl_decl_msvc.h
	base/stl_decl_osx.h
	base/stringprintf.h
	base/strtoint.h
	base/template_util.h
	base/type_traits.h
)

set(s2includes_strings
	strings/ascii_ctype.h
	strings/split.h
	strings/stringprintf.h
	strings/strutil.h
)

set(s2includes_util_coding
	util/coding/coder.h
	util/coding/varint.h
)

set(s2includes_util_endian
	util/endian/endian.h
)

set(s2includes_util_hash
	util/hash/hash.h
	util/hash/hash_jenkins_lookup2.h
)

set(s2includes_util_math
	util/math/mathlimits.h
	util/math/mathutil.h
	util/math/matrix3x3.h
	util/math/matrix3x3-inl.h
	util/math/vector2.h
	util/math/vector2-inl.h
	util/math/vector3.h
	util/math/vector3-inl.h
	util/math/vector4.h
	util/math/vector4-inl.h
)

add_library(s2util SHARED ${s2util_files})
target_link_libraries(s2util ${OPENSSL_LIBRARIES})

add_library(s2cellid SHARED ${s2cellid_files})
target_link_libraries(s2cellid s2util)

add_library(s2 SHARED ${s2_files})
target_link_libraries(s2 s2cellid s2util ${OPENSSL_LIBRARIES} pthread)

install(TARGETS s2util s2cellid s2
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

CONFIGURE_FILE(
	${CMAKE_CURRENT_SOURCE_DIR}/s2.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/s2.pc
	@ONLY
)

CONFIGURE_FILE(
	${CMAKE_CURRENT_SOURCE_DIR}/s2cellid.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/s2cellid.pc
	@ONLY
)

# Install header files
install(FILES ${s2includes} DESTINATION include/s2)
install(FILES ${s2includes_base} DESTINATION include/s2/base)
install(FILES ${s2includes_strings} DESTINATION include/s2/strings)
install(FILES ${s2includes_util_coding} DESTINATION include/s2/util/coding)
install(FILES ${s2includes_util_endian} DESTINATION include/s2/util/endian)
install(FILES ${s2includes_util_hash} DESTINATION include/s2/util/hash)
install(FILES ${s2includes_util_math} DESTINATION include/s2/util/math)
install(FILES ${CMAKE_BINARY_DIR}/s2.pc DESTINATION lib/pkgconfig)
install(FILES ${CMAKE_BINARY_DIR}/s2cellid.pc DESTINATION lib/pkgconfig)

