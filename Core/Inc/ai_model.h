#ifndef AI_MODEL_H
#define AI_MODEL_H

#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    double var11[3];
    double var12[3];
    double var13[3];
    double var14[3];
    double var15[3];
    double var16[3];
    double var17[3];
    double var18[3];
    double var19[3];
    double var20[3];
    double var21[3];
    double var22[3];
    double var23[3];
    double var24[3];
    double var25[3];
    double var26[3];
    double var27[3];
    double var28[3];
    double var29[3];
    double var30[3];
    double var31[3];
    double var32[3];
    double var33[3];
    double var34[3];
    double var35[3];
    double var36[3];
    double var37[3];
    double var38[3];
    double var39[3];
    double var40[3];
    double var41[3];
    double var42[3];
    double var43[3];
    double var44[3];
    double var45[3];
    double var46[3];
    double var47[3];
    double var48[3];
    double var49[3];
    double var50[3];
    if (input[2] <= 1.3115000128746033) {
        memcpy(var50, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.6549999713897705) {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var50, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[0] <= 1.1225285530090332) {
                    memcpy(var50, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var50, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var50, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    double var51[3];
    if (input[1] <= 0.2853666841983795) {
        if (input[3] <= 0.9230000078678131) {
            memcpy(var51, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var51, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var51, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var50, var51, 3, var49);
    double var52[3];
    if (input[3] <= 0.9214999675750732) {
        if (input[1] <= 0.2690798491239548) {
            if (input[0] <= 1.0970714092254639) {
                memcpy(var52, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[0] <= 1.1225285530090332) {
                    memcpy(var52, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var52, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var52, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var52, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var49, var52, 3, var48);
    double var53[3];
    if (input[1] <= 0.08949804399162531) {
        memcpy(var53, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[0] <= 1.044600009918213) {
            memcpy(var53, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var53, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var48, var53, 3, var47);
    double var54[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var54, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.2646366208791733) {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var54, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var54, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var54, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var47, var54, 3, var46);
    double var55[3];
    if (input[4] <= 0.4545000046491623) {
        memcpy(var55, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[3] <= 0.16049999743700027) {
            memcpy(var55, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[4] <= 1.1759999990463257) {
                memcpy(var55, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.7080000042915344) {
                    memcpy(var55, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var55, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var46, var55, 3, var45);
    double var56[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var56, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.546500027179718) {
            if (input[0] <= 0.9964000284671783) {
                memcpy(var56, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[2] <= 1.9955000281333923) {
                    memcpy(var56, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var56, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var56, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var45, var56, 3, var44);
    double var57[3];
    if (input[0] <= 1.044600009918213) {
        memcpy(var57, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    } else {
        if (input[2] <= 1.2599999904632568) {
            memcpy(var57, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[4] <= 1.546500027179718) {
                memcpy(var57, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var57, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var44, var57, 3, var43);
    double var58[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var58, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.30898770689964294) {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var58, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[4] <= 1.1179999709129333) {
                    memcpy(var58, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var58, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var58, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var43, var58, 3, var42);
    double var59[3];
    if (input[1] <= 0.2690798491239548) {
        if (input[1] <= 0.09061189368367195) {
            memcpy(var59, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var59, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var59, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var42, var59, 3, var41);
    double var60[3];
    if (input[1] <= 0.2690798491239548) {
        if (input[4] <= 0.47700000554323196) {
            memcpy(var60, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var60, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var60, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var41, var60, 3, var40);
    double var61[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var61, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.1650000214576721) {
            memcpy(var61, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[1] <= 0.2239534631371498) {
                memcpy(var61, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var61, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var40, var61, 3, var39);
    double var62[3];
    if (input[2] <= 1.2854999899864197) {
        memcpy(var62, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.8169999718666077) {
            if (input[0] <= 1.0007857382297516) {
                memcpy(var62, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[2] <= 1.9955000281333923) {
                    memcpy(var62, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 0.2407528981566429) {
                        memcpy(var62, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var62, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var62, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var39, var62, 3, var38);
    double var63[3];
    if (input[2] <= 1.2710000276565552) {
        memcpy(var63, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[3] <= 0.3449999913573265) {
            memcpy(var63, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var63, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var38, var63, 3, var37);
    double var64[3];
    if (input[1] <= 0.2853666841983795) {
        if (input[4] <= 0.47700000554323196) {
            memcpy(var64, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var64, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.801499992609024) {
                    memcpy(var64, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var64, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var64, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var37, var64, 3, var36);
    double var65[3];
    if (input[3] <= 0.9214999675750732) {
        if (input[3] <= 0.3799999952316284) {
            memcpy(var65, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var65, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var65, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var36, var65, 3, var35);
    double var66[3];
    if (input[3] <= 0.9194999635219574) {
        if (input[4] <= 1.5565000176429749) {
            if (input[1] <= 0.2690798491239548) {
                if (input[3] <= 0.7560000121593475) {
                    memcpy(var66, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[0] <= 1.0970714092254639) {
                        memcpy(var66, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var66, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var66, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var66, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var66, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var35, var66, 3, var34);
    double var67[3];
    if (input[3] <= 0.3799999952316284) {
        memcpy(var67, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 0.5029999986290932) {
            memcpy(var67, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var67, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.6840000152587891) {
                    memcpy(var67, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var67, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var34, var67, 3, var33);
    double var68[3];
    if (input[4] <= 0.5029999986290932) {
        memcpy(var68, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[0] <= 1.0346571803092957) {
            memcpy(var68, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var68, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[4] <= 1.5565000176429749) {
                    if (input[0] <= 1.1225285530090332) {
                        memcpy(var68, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var68, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var68, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var33, var68, 3, var32);
    double var69[3];
    if (input[1] <= 0.2646366208791733) {
        if (input[3] <= 0.9194999635219574) {
            if (input[4] <= 1.1759999990463257) {
                memcpy(var69, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.7560000121593475) {
                    memcpy(var69, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var69, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var69, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var69, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var32, var69, 3, var31);
    double var70[3];
    if (input[4] <= 0.47700000554323196) {
        memcpy(var70, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.2690798491239548) {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var70, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[1] <= 0.2407528981566429) {
                    memcpy(var70, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var70, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var70, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var31, var70, 3, var30);
    double var71[3];
    if (input[4] <= 0.47700000554323196) {
        memcpy(var71, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.5415000319480896) {
            if (input[3] <= 0.3414999917149544) {
                memcpy(var71, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var71, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var71, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var30, var71, 3, var29);
    double var72[3];
    if (input[1] <= 0.08745900634676218) {
        memcpy(var72, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.1650000214576721) {
            memcpy(var72, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[0] <= 1.1068856716156006) {
                memcpy(var72, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[0] <= 1.1150142550468445) {
                    memcpy(var72, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 0.3184300512075424) {
                        memcpy(var72, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var72, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var29, var72, 3, var28);
    double var73[3];
    if (input[3] <= 0.3449999913573265) {
        memcpy(var73, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.08745900634676218) {
            memcpy(var73, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var73, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.8034999966621399) {
                    memcpy(var73, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var73, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var28, var73, 3, var27);
    double var74[3];
    if (input[4] <= 0.5029999986290932) {
        memcpy(var74, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.2853666841983795) {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var74, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var74, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var74, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var27, var74, 3, var26);
    double var75[3];
    if (input[1] <= 0.08374394616112113) {
        memcpy(var75, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.29990094900131226) {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var75, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var75, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var75, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var26, var75, 3, var25);
    double var76[3];
    if (input[3] <= 0.8739999830722809) {
        if (input[1] <= 0.2853666841983795) {
            memcpy(var76, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var76, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var76, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var25, var76, 3, var24);
    double var77[3];
    if (input[3] <= 0.8739999830722809) {
        if (input[1] <= 0.2853666841983795) {
            memcpy(var77, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var77, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var77, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var24, var77, 3, var23);
    double var78[3];
    if (input[1] <= 0.2646366208791733) {
        if (input[4] <= 0.47700000554323196) {
            memcpy(var78, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var78, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var78, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var23, var78, 3, var22);
    double var79[3];
    if (input[1] <= 0.2853666841983795) {
        if (input[2] <= 1.3119999766349792) {
            memcpy(var79, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var79, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[0] <= 1.094071388244629) {
                    memcpy(var79, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var79, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var79, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var22, var79, 3, var21);
    double var80[3];
    if (input[1] <= 0.25991813838481903) {
        if (input[3] <= 0.9214999675750732) {
            memcpy(var80, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var80, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var80, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var21, var80, 3, var20);
    double var81[3];
    if (input[1] <= 0.2646366208791733) {
        if (input[1] <= 0.08578298380598426) {
            memcpy(var81, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var81, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var81, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var20, var81, 3, var19);
    double var82[3];
    if (input[4] <= 0.47700000554323196) {
        memcpy(var82, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.5565000176429749) {
            if (input[1] <= 0.2853666841983795) {
                if (input[2] <= 1.9955000281333923) {
                    memcpy(var82, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[1] <= 0.2407528981566429) {
                        memcpy(var82, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var82, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var82, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var82, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var19, var82, 3, var18);
    double var83[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var83, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.2646366208791733) {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var83, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var83, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var83, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var18, var83, 3, var17);
    double var84[3];
    if (input[3] <= 0.9194999635219574) {
        if (input[0] <= 1.0055428743362427) {
            memcpy(var84, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var84, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.6840000152587891) {
                    memcpy(var84, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var84, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var84, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var17, var84, 3, var16);
    double var85[3];
    if (input[4] <= 0.5034999921917915) {
        memcpy(var85, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[0] <= 1.044600009918213) {
            memcpy(var85, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[2] <= 1.9955000281333923) {
                memcpy(var85, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var85, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var16, var85, 3, var15);
    double var86[3];
    if (input[3] <= 0.9230000078678131) {
        if (input[1] <= 0.2690798491239548) {
            memcpy(var86, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var86, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var86, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var15, var86, 3, var14);
    double var87[3];
    if (input[4] <= 0.5029999986290932) {
        memcpy(var87, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.6449999809265137) {
            if (input[2] <= 1.9955000281333923) {
                if (input[1] <= 0.2646366208791733) {
                    memcpy(var87, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var87, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var87, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var87, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var14, var87, 3, var13);
    double var88[3];
    if (input[4] <= 0.50849998742342) {
        memcpy(var88, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[3] <= 0.3799999952316284) {
            memcpy(var88, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var88, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var13, var88, 3, var12);
    double var89[3];
    if (input[4] <= 0.47700000554323196) {
        memcpy(var89, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[3] <= 0.3799999952316284) {
            memcpy(var89, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var89, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var12, var89, 3, var11);
    double var90[3];
    if (input[4] <= 0.5029999986290932) {
        memcpy(var90, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[1] <= 0.27627992630004883) {
            memcpy(var90, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var90, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var11, var90, 3, var10);
    double var91[3];
    if (input[3] <= 0.9214999675750732) {
        if (input[1] <= 0.30898770689964294) {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var91, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[4] <= 1.1179999709129333) {
                    memcpy(var91, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var91, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var91, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    } else {
        memcpy(var91, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var10, var91, 3, var9);
    double var92[3];
    if (input[3] <= 0.9194999635219574) {
        if (input[0] <= 1.044600009918213) {
            memcpy(var92, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[3] <= 0.7560000121593475) {
                memcpy(var92, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[4] <= 1.0185000002384186) {
                    memcpy(var92, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var92, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var92, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    }
    add_vectors(var9, var92, 3, var8);
    double var93[3];
    if (input[2] <= 1.2599999904632568) {
        memcpy(var93, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.5565000176429749) {
            if (input[3] <= 0.3414999917149544) {
                memcpy(var93, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if (input[2] <= 1.9955000281333923) {
                    memcpy(var93, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    if (input[4] <= 1.315999984741211) {
                        memcpy(var93, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var93, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                }
            }
        } else {
            memcpy(var93, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var8, var93, 3, var7);
    double var94[3];
    if (input[4] <= 0.5029999986290932) {
        memcpy(var94, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[3] <= 0.3449999913573265) {
            memcpy(var94, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            memcpy(var94, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var7, var94, 3, var6);
    double var95[3];
    if (input[1] <= 0.08357030432671309) {
        memcpy(var95, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.5565000176429749) {
            if (input[0] <= 1.0007857382297516) {
                memcpy(var95, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var95, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var95, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var6, var95, 3, var5);
    double var96[3];
    if (input[4] <= 0.5034999921917915) {
        memcpy(var96, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[4] <= 1.5565000176429749) {
            if (input[0] <= 0.9964000284671783) {
                memcpy(var96, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                memcpy(var96, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var96, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    add_vectors(var5, var96, 3, var4);
    double var97[3];
    if (input[1] <= 0.2690798491239548) {
        if (input[1] <= 0.09374316409230232) {
            memcpy(var97, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[4] <= 1.1759999990463257) {
                memcpy(var97, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[4] <= 1.2214999794960022) {
                    memcpy(var97, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var97, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var97, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var4, var97, 3, var3);
    double var98[3];
    if (input[1] <= 0.25991813838481903) {
        if (input[4] <= 0.47700000554323196) {
            memcpy(var98, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            if (input[0] <= 1.0970714092254639) {
                memcpy(var98, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if (input[3] <= 0.6604999899864197) {
                    memcpy(var98, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var98, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        memcpy(var98, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
    }
    add_vectors(var3, var98, 3, var2);
    double var99[3];
    if (input[4] <= 0.4545000046491623) {
        memcpy(var99, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if (input[0] <= 1.044600009918213) {
            memcpy(var99, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        } else {
            if (input[0] <= 1.1150142550468445) {
                memcpy(var99, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var99, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    add_vectors(var2, var99, 3, var1);
    mul_vector_number(var1, 0.02, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}

#endif
