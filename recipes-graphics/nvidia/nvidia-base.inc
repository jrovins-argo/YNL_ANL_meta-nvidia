SUMMARY = "NVidia Binary Graphics Driver"
LICENSE = "NVIDIA-Proprietary"

NVIDIA_ARCHIVE_NAME = "NVIDIA-Linux-${TARGET_ARCH}-${PV}"
NVIDIA_SRC = "${WORKDIR}/${NVIDIA_ARCHIVE_NAME}"

# The format of the download path has changed for tesla type drivers,
# To revert to the standard nvidia path, use:
# https://us.download.nvidia.com/XFree86/Linux-${TARGET_ARCH}/${PV}/${NVIDIA_ARCHIVE_NAME}.run 
# The tesla path looks like this:
# https://us.download.nvidia.com/tesla/${PV}/${NVIDIA_ARCHIVE_NAME}.run \


SRC_URI = " \
    https://us.download.nvidia.com/tesla/${PV}/${NVIDIA_ARCHIVE_NAME}.run \
    "

S = "${NVIDIA_SRC}/kernel"

do_unpack() {
    chmod +x ${DL_DIR}/${NVIDIA_ARCHIVE_NAME}.run
    rm -rf ${NVIDIA_SRC}
    ${DL_DIR}/${NVIDIA_ARCHIVE_NAME}.run -x --target ${NVIDIA_SRC}
}

do_make_scripts[noexec] = "1"
